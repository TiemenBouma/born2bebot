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

int	rate_gamestate(t_vars *v, t_gamestate *gamestate)
{
	int color = game_winner(v, gamestate);

	if (!is_empty(v, gamestate, gamestate->move.column))
	{
		// dprintf(2, "we will lose if we play in col: [%d]\n", gamestate->move.column);
		return INT_MIN;
	}
	if (is_my_color(&v->gameinput, color))
	{
		// dprintf(2, "we can win a game: play color: [%d] in col: [%d]\n", color, gamestate->move.column);
		return INT_MAX;
	}
	if (is_opp_color(&v->gameinput, color))
	{
		return INT_MIN;
	}
	return 0;
}

t_gamestate*	clone_gamestates(t_vars *v, t_gamestate *src, int amount_gamestates)
{
	t_gamestate*	result = calloc(amount_gamestates, sizeof(t_gamestate));

	for (int i = 0; i < amount_gamestates; ++i)
	{
		copy_gamestate(v, &result[i], src);
	}
	return result;
}

void	set_drop_move(t_vars *v, t_move *dst, int col, int chip_color)
{
	t_move tmp = {drop, col, chip_color, 0};
	memcpy(dst, &tmp, sizeof(t_move));
}

void	set_rotate_move(t_vars *v, t_move *dst, int direction)
{
	t_move tmp = {rotate, 0, 0, direction};
	memcpy(dst, &tmp, sizeof(t_move));
}

t_move*	get_legal_moves(t_vars *v, int amount_moves)
{
	t_move* result = calloc(amount_moves, sizeof(t_move));

	const int	amount_of_columns = v->gameinput.grid_size * 2 - 1;
	const int	amount_of_color_choices = v->chips_data.mine.choices;
	const int	amount_of_rotations = 6;

	int i = 0;
	int col = v->gameinput.min_column;
	for (; i < amount_of_columns; ++i, ++col)
	{
		set_drop_move(v, &result[i], col, v->chips_data.mine.drawn_chips[0]);
	}
	col = v->gameinput.min_column;
	if (v->chips_data.mine.choices == 2)
	{
		for (; i < 2 * amount_of_columns; ++i, ++col)
		{
			set_drop_move(v, &result[i], col, v->chips_data.mine.drawn_chips[1]);
		}
	}
	int direction = 0;
	for (; i < amount_moves; ++i, ++direction)
	{
		set_rotate_move(v, &result[i], direction);
	}
	return result;
}

void	copy_moves_to_gamestate(t_vars *v, t_move *legal_moves, t_gamestate *gamestates, int amount)
{
	for (int i = 0; i < amount; ++i)
	{
		memcpy(&gamestates[i].move, &legal_moves[i], sizeof(t_move));
		process_move(v, &gamestates[i], &gamestates[i].move);
		gamestates[i].rating = rate_gamestate(v, &gamestates[i]);
	}
}

void	*bot(void *ptr)
{
	t_vars*		v = (t_vars *)ptr;
	v->current.amount_possible_moves = v->chips_data.mine.choices * (v->gameinput.grid_size * 2 - 1) + 6;	// dprintf(2, "there are [%d] moves\n", amount_moves);


	v->current.deeper = clone_gamestates(v, &v->current, v->current.amount_possible_moves);
	t_move *legal_moves = get_legal_moves(v, v->current.amount_possible_moves);
	copy_moves_to_gamestate(v, legal_moves, v->current.deeper, v->current.amount_possible_moves);
	free(legal_moves);

	int highest_rating = INT_MIN;
	for (int i = 0; i < v->current.amount_possible_moves; ++i)
	{
		if (v->current.deeper[i].rating > highest_rating)
		{
			highest_rating = v->current.deeper[i].rating;
			set_next_move(&v->next_move, &v->current.deeper[i].move);
		}
	}


	if (highest_rating == 0)
		make_random_move(v, &v->next_move, &v->gameinput, &v->chips_data.mine);
	free_all_gamestates(v);
	v->end_of_turn = true;
	pthread_exit(NULL);
	return NULL;
}
