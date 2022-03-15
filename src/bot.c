#include "born2bebot.h"
#include "utils.h"
#include <pthread.h>

#ifdef __linux__
# include <bsd/stdlib.h>
#else
# include <stdlib.h>
#endif

int	make_random_move(t_vars *v, t_move *next_move, t_gameinput *g, t_my_chips_data *mine)
{
	next_move->type = drop;
	next_move->color = mine->drawn_chips[arc4random_uniform(2)];
	// dprintf(2, "min col: [%d], max col [%d]\n", g->min_column, g->max_column);
	next_move->column = arc4random_uniform(2 * g->max_column + 1) - g->max_column;

	if (!is_empty(v, &v->current, next_move->column))
		return make_random_move(v, next_move, g, mine);
	return 0;
}

void	set_next_move(t_move *next_move, t_move *src)
{
	next_move->type = src->type;
	next_move->column = src->column;
	next_move->color = src->color;
	next_move->direction = src->direction;
}

t_gamestate*	create_gamestates(t_vars *v, t_gamestate *src, int amount)
{
	t_gamestate*	result = calloc(amount, sizeof(t_gamestate));

	int i = 0;
	//check color 1
	for ((void)NULL; i < v->gameinput.grid_size * 2 - 1; ++i)
	{
		// dprintf(2, "i = [%d]\n", i);
		copy_gamestate(v, &result[i], src);
		t_move m = {drop, i - (v->gameinput.grid_size - 1), v->chips_data.mine.drawn_chips[0], 0};
		memcpy(&result[i].move, &m, sizeof(t_move));
		process_move(v, &result[i], &m);
		int color = win_check_all_tiles(v, &result[i]);
		// dprintf(2, "color = [%d]\n", color);
		if (is_my_color(&v->gameinput, color))
		{
			result[i].rating = INT_MAX;
			// dprintf(2, "we can win a game! (1) color: [%d] col: [%d]\n", color, m.column);
			// exit(0);
		}
		if (!is_empty(v, &result[i], m.column))
		{
			result[i].rating = INT_MIN;
			// dprintf(2, "we will lose in col: [%d]\n", m.column);
		}
	}
	// dprintf(2, "moving to next one (1)\n");
	// dprintf(2, "-----------min col = [%d]\n", v->gameinput.min_column);
	//check color2
	if (v->chips_data.mine.choices == 2)
	{
		for (int _col = v->gameinput.min_column; i < 2 * (v->gameinput.grid_size * 2 - 1); ++i, _col++)
		{
			// dprintf(2, "i = [%d] / [%d]\n", i, 2 * (v->gameinput.grid_size * 2 - 1));
			copy_gamestate(v, &result[i], src);
			t_move m = {drop, _col, v->chips_data.mine.drawn_chips[1], 0};
			memcpy(&result[i].move, &m, sizeof(t_move));
			// dprintf(2, "move col: [%d]\n", i - 2 * (v->gameinput.grid_size - 1));
			process_move(v, &result[i], &m);
			int color = win_check_all_tiles(v, &result[i]);
			// dprintf(2, "color = [%d]\n", color);
			if (is_my_color(&v->gameinput, color))
			{
				result[i].rating = INT_MAX;
				// dprintf(2, "we can win a game! (2) color: [%d] col: [%d]\n", color, m.column);
				// exit(0);
			}
			if (!is_empty(v, &result[i], m.column))
			{
				result[i].rating = INT_MIN;
				// dprintf(2, "we will lose in col: [%d]\n", m.column);
			}
		}
	}
	// dprintf(2, "moving to next one (2)\n");
	for (int dir = 0; i < amount; ++i, dir++)
	{
		copy_gamestate(v, &result[i], src);
		t_move m = {rotate, 0, 0, dir};
		memcpy(&result[i].move, &m, sizeof(t_move));
		process_move(v, &result[i], &m);
		int color = win_check_all_tiles(v, &result[i]);
		// dprintf(2, "color = [%d]\n", color);
		if (is_my_color(&v->gameinput, color))
		{
			result[i].rating = INT_MAX;
			// dprintf(2, "we can win a game! (3) dir: [%d]\n", dir);
			// exit(0);
		}
		else if (is_opp_color(&v->gameinput, color))
		{
			result[i].rating = INT_MIN;
			// dprintf(2, "we can loose a game! (3) dir: [%d]\n", dir);
		}
	}
	return result;
}

void    *bot(void *ptr)
{
	t_vars*		v = (t_vars *)ptr;
	const int	amount_moves = v->chips_data.mine.choices * (v->gameinput.grid_size * 2 - 1) + 6;
				// dprintf(2, "there are [%d] moves\n", amount_moves);

	make_random_move(v, &v->next_move, &v->gameinput, &v->chips_data.mine);
	t_gamestate *result = create_gamestates(v, &v->current, amount_moves);
	t_gamestate *result_opp[amount_moves];
	t_move *best_move_opp;	
	//free that (deep)stuff

	int highest_rating = INT_MIN;
	//dprintf(2, "IN BOT[%d]\n", highest_rating);
	int highest_rating_opp;
	int opp_moves;
	for (int my_moves = 0; my_moves < amount_moves; my_moves++)
	{
		if (result[my_moves].rating < INT_MAX && result[my_moves].rating > INT_MIN) 
		{
			result_opp[my_moves] = create_gamestates(v, &result[my_moves], amount_moves);
			highest_rating_opp = INT_MIN;
			opp_moves = 0;
			while (opp_moves < amount_moves) 
			{
				if (result_opp[my_moves][opp_moves].rating > highest_rating_opp && result_opp[my_moves][opp_moves].move.type == drop)
				{
					highest_rating_opp = result_opp[my_moves][opp_moves].rating;
					best_move_opp = &result_opp[my_moves][opp_moves].move;
				}
				opp_moves++;
			}
			// if (highest_rating_opp == INT_MAX && result_opp[my_moves][opp_moves].move.type == drop)
			// {
			// 	set_next_move(&v->next_move, &result_opp[my_moves][opp_moves].move);
			// 	result[my_moves].rating = (highest_rating_opp) * -1;
			// 	dprintf(2, "doing the trick\n");
			// 	break ;
			// }
			if (highest_rating_opp > result[my_moves].rating)
			{
				result[my_moves].rating = (highest_rating_opp) * -1; // (of INT_MIN )als rating van opponent hoger is dan die van ons word de rating geflipt in onze rating gestopt.
				//set_next_move(&v->next_move, best_move_opp);
			// 	dprintf(2, "NA berekening[%d]\n", result[my_moves].rating);
			// 	//dprintf(2, "\n\nPRINTF|%d|\n\n", (void *)&result_opp[my_moves][opp_moves]);
			}
		}
		// if (!is_empty(v, &result[my_moves], result[my_moves].move.column /*next_move->column */))
		// 	result[my_moves].rating = INT_MIN;
		if (result[my_moves].rating > highest_rating && result[my_moves].move.type == drop)
		{
			highest_rating = result[my_moves].rating;
			if (highest_rating > 0)
			{
				set_next_move(&v->next_move, &result[my_moves].move);
			}
			//dprintf(2, "NA berekening[%d]\n", highest_rating);
		}
	}
	v->end_of_turn = true;
	pthread_exit(NULL);
	return NULL;
}
