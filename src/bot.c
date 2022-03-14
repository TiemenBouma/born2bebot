#include "born2bebot.h"
#include "utils.h"
#include <pthread.h>
#include <stdlib.h>

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
	for ((void)NULL; i < v->gameinput.grid_size * 2 - 1; ++i)
	{
		// dprintf(2, "i = [%d]\n", i);
		copy_gamestate(v, &result[i], src);
		t_move m = {drop, i - (v->gameinput.grid_size - 1), v->chips_data.mine.drawn_chips[0], 0};
		memcpy(&result[i].move, &m, sizeof(t_move));
		process_move(v, &result[i], &m);
		int color = game_winner(v, &result[i]);
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
			int color = game_winner(v, &result[i]);
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
		int color = game_winner(v, &result[i]);
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
	t_gamestate *result = create_gamestates(v, &v->current, amount_moves);		//free that (deep)stuff

	int highest_rating = INT_MIN;
	for (int i = 0; i < amount_moves; i++)
	{
		if (result[i].rating > highest_rating && result[i].move.type == drop)
		{
			highest_rating = result[i].rating;
			set_next_move(&v->next_move, &result[i].move);
		}
	}
	v->end_of_turn = true;
	pthread_exit(NULL);
	return NULL;
}
