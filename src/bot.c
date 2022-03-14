#include "born2bebot.h"
#include "utils.h"
#include <pthread.h>
#include <stdlib.h>

void	make_random_move(t_move *next_move, t_gameinput *g, t_my_chips_data *mine)
{
	next_move->type = drop;
	next_move->color = mine->drawn_chips[arc4random_uniform(2)];
	dprintf(2, "min col: [%d], max col [%d]\n", g->min_column, g->max_column);
	next_move->column = arc4random_uniform(2 * g->max_column + 1) - g->max_column;
}

void	set_next_move(t_move *next_move, t_gameinput *g, t_my_chips_data *mine)
{
	make_random_move(next_move, g, mine);
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
		process_move(v, &result[i], &m);
		int color = game_winner(v, &result[i]);
		// dprintf(2, "color = [%d]\n", color);
		if (is_my_color(&v->gameinput, color))
		{
			dprintf(2, "we won a game! (1)\n");
		}
		else if (is_opp_color(&v->gameinput, color))
		{
			dprintf(2, "we lost a game! (1)\n");
		}
	}
	dprintf(2, "moving to next one (1)\n");
	if (v->chips_data.mine.choices == 2)
	{
		for (int _col = v->gameinput.min_column; i < 2 * (v->gameinput.grid_size * 2 - 1); ++i, v->gameinput.min_column++)
		{
			dprintf(2, "i = [%d] / [%d]\n", i, 2 * (v->gameinput.grid_size * 2 - 1));
			copy_gamestate(v, &result[i], src);
			t_move m = {drop, _col, v->chips_data.mine.drawn_chips[1], 0};
			dprintf(2, "move col: [%d]\n", i - 2 * (v->gameinput.grid_size - 1));
			dprintf(2, "wat1\n");
			process_move(v, &result[i], &m);
			dprintf(2, "wat2\n");
			int color = game_winner(v, &result[i]);
			// dprintf(2, "color = [%d]\n", color);
			if (is_my_color(&v->gameinput, color))
			{
				dprintf(2, "we won a game! (2)\n");
			}
			else if (is_opp_color(&v->gameinput, color))
			{
				dprintf(2, "we lost a game! (2)\n");
			}
		}
	}
	dprintf(2, "moving to next one (2)\n");
	for (int dir = 0; i < amount; ++i, dir++)
	{
		copy_gamestate(v, &result[i], src);
		t_move m = {rotate, 0, 0, dir};
		process_move(v, &result[i], &m);
		int color = game_winner(v, &result[i]);
		// dprintf(2, "color = [%d]\n", color);
		if (is_my_color(&v->gameinput, color))
		{
			dprintf(2, "we won a game! (3)\n");
		}
		else if (is_opp_color(&v->gameinput, color))
		{
			dprintf(2, "we lost a game! (3)\n");
		}
	}
	return result;
}

void    *bot(void *ptr)
{
	t_vars*		v = (t_vars *)ptr;
	const int	amount_moves = v->chips_data.mine.choices * (v->gameinput.grid_size * 2 - 1) + 6;
				// dprintf(2, "there are [%d] moves\n", amount_moves);

	// t_gamestate *next_depth = create_gamestates(v, &v->current, amount_moves);		//free that stuff




	set_next_move(&v->next_move, &v->gameinput, &v->chips_data.mine);
	v->end_of_turn = true;
	pthread_exit(NULL);
	return NULL;
}
