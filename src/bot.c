#include "born2bebot.h"
#include "utils.h"
#include <pthread.h>

#ifdef __linux__
# include <bsd/stdlib.h>
#else
# include <stdlib.h>
#endif


void	set_next_move(t_move *next_move, t_move *src)
{
	next_move->type = src->type;
	next_move->column = src->column;
	next_move->color = src->color;
	next_move->direction = src->direction;
}

int	make_random_move(t_vars *v, t_move *next_move, t_gameinput *g, t_my_chips_data *mine)
{
	next_move->type = drop;
	next_move->color = mine->drawn_chips[arc4random_uniform(2)];
	next_move->column = arc4random_uniform(2 * g->max_column + 1) - g->max_column;

	if (!is_empty(v, &v->current, next_move->column))
		return make_random_move(v, next_move, g, mine);
	return 0;
}

int	make_random_of_highest_rating_move(t_vars *v, t_move *next_move, int highest_rating)
{
	int choice;
	int count = 0;
	for (int i = 0; i < v->current.amount_possible_moves; i++)
	{
		if (v->current.deeper[i].rating == highest_rating && v->current.deeper[i].move.type == drop)
			count++;
	}
	choice = arc4random_uniform(count);
	count = 0;
	for (int i = 0; i < v->current.amount_possible_moves; i++)
	{
		if (v->current.deeper[i].rating == highest_rating && v->current.deeper[i].move.type == drop)
		{
			if (count == choice)
			{
				set_next_move(&v->next_move, &v->current.deeper[i].move);
				break ;
			}
			count++;
		}	
	}
	return 0;
}


int	rate_gamestate(t_vars *v, t_gamestate *gamestate)
{
	int color = game_winner(v, gamestate);

	if (!is_empty(v, gamestate, gamestate->move.column))
	{
		// dprintf(2, "we will lose if we play in col: [%d]\n", gamestate->move.column);
		return INT_MIN;
	}
	// if (gamestate->turn == 0)
	{
		if (is_my_color(&v->gameinput, color))
		{
			// dprintf(2, "we can win a game: play color: [%d] in col: [%d]\n", color, gamestate->move.column);
			return INT_MAX;
		}
	}
	// if (gamestate->turn == 1)
	{
		if (is_opp_color(&v->gameinput, color))
		{
			// dprintf(2, "we can win a game: play color: [%d] in col: [%d]\n", color, gamestate->move.column);
			return INT_MIN;
		}
	}
	// if (is_opp_color(&v->gameinput, color))
	// {
	// 	return INT_MIN;
	// }
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

void	set_drop_move(t_move *dst, int col, int chip_color)
{
	t_move tmp = {drop, col, chip_color, 0};
	memcpy(dst, &tmp, sizeof(t_move));
}

void	set_rotate_move(t_move *dst, int direction)
{
	t_move tmp = {rotate, 0, 0, direction};
	memcpy(dst, &tmp, sizeof(t_move));
}

t_move*	get_legal_moves(t_vars *v, int amount_moves, int color1, int color2)
{
	t_move* result = calloc(amount_moves, sizeof(t_move));

	const int	amount_of_columns = v->gameinput.grid_size * 2 - 1;

	int i = 0;
	int column = v->gameinput.min_column;
	for (; i < amount_of_columns; ++i, ++column)
	{
		set_drop_move(&result[i], column, color1);
	}
	column = v->gameinput.min_column;
	if (color1 != color2)
	{
		for (; i < 2 * amount_of_columns; ++i, ++column)
		{
			set_drop_move(&result[i], column, color2);
		}
	}
	int direction = 0;
	for (; i < amount_moves; ++i, ++direction)
	{
		set_rotate_move(&result[i], direction);
	}
	// for (int i = 0; i < amount_moves; i++)
	// {
	// 	dprintf(2, "type = [%d], col = [%d], color = [%d], dir = [%d]\n", result[i].type, result[i].column, result[i].color, result[i].direction);
	// }
	return result;
}

void	copy_moves_to_gamestate(t_vars *v, t_move *legal_moves, t_gamestate *gamestates, int amount)
{
	for (int i = 0; i < amount; ++i)
	{
		memcpy(&gamestates[i].move, &legal_moves[i], sizeof(t_move));
		if (is_empty(v, &gamestates[i], gamestates[i].move.column))
		{
			process_move(v, &gamestates[i], &gamestates[i].move);
			gamestates[i].rating = rate_gamestate(v, &gamestates[i]);
		}
		else
		{
			gamestates[i].rating = INT_MIN;
		}
		gamestates[i].turn = !gamestates[i].turn;
	}
}

void	search_best_move(t_vars *v)
{
	int highest_rating = INT_MIN;

	for (int i = 0; i < v->current.amount_possible_moves; ++i)
	{
		dprintf(2, "rating i = %d: %d\n", i, v->current.deeper[i].rating);
		if (v->current.deeper[i].rating > highest_rating)
		{
			highest_rating = v->current.deeper[i].rating;
			set_next_move(&v->next_move, &v->current.deeper[i].move);
		}
	}
	if (highest_rating == 0)
		make_random_of_highest_rating_move(v, &v->next_move, highest_rating);
}

// int	count_possible_moves(t_vars *v, t_gamestate *g)
// {

// }

void	*bot(void *ptr)
{
	t_vars*		v = (t_vars *)ptr;
	int			opp_amount_moves = 2 * (v->gameinput.grid_size * 2 - 1) + 6;
	// v->current.amount_possible_moves = count_possible_moves(v, &v->current);
	v->current.amount_possible_moves = v->chips_data.mine.choices * (v->gameinput.grid_size * 2 - 1) + 6;	// dprintf(2, "there are [%d] moves\n", amount_moves);

	v->current.deeper = clone_gamestates(v, &v->current, v->current.amount_possible_moves);
	t_move *legal_moves = get_legal_moves(v, v->current.amount_possible_moves, v->chips_data.mine.drawn_chips[0], v->chips_data.mine.drawn_chips[1]);
	copy_moves_to_gamestate(v, legal_moves, v->current.deeper, v->current.amount_possible_moves);
	free(legal_moves);
 // we hebben nu een array van gamestates voor onze eigen mogelijkheden
 // we gaan voor iedere mogelijkheid kijken wat voor invloed het heeft op de winkans van de tegenstander

	for (int i = 0; i < v->current.amount_possible_moves; i++)
	{
		//dprintf(2, "index %d:\n", i);
		if (v->current.deeper[i].rating == INT_MAX)
			break ;
		v->current.deeper[i].amount_possible_moves = opp_amount_moves;
		v->current.deeper[i].deeper = clone_gamestates(v, &v->current.deeper[i], opp_amount_moves);
		int opp_id = !v->gameinput.player_id;
		t_move *opp_legal_moves = get_legal_moves(v, opp_amount_moves, opp_id * 2, opp_id * 2 + 1);
		copy_moves_to_gamestate(v, opp_legal_moves, v->current.deeper[i].deeper, opp_amount_moves);
		// for (int j = 0; j < amount_moves; j++)
		// {
		// 	dprintf(2, "index j %d: column: <%d>, \n", i, v->current.deeper[i].deeper[j].move.column);
		// }
		free(opp_legal_moves);
	}
	//exit(0);
	//int highest_rating = INT_MIN;
	int highest_rating_opp;
	//int opp_moves;
	// we zoeken of de tegenstander een int_max rating heeft
	for (int i = 0; i < v->current.amount_possible_moves; i++)
	{
		if (v->current.deeper[i].rating == INT_MAX)
			break ;
		for (int j = 0; j < opp_amount_moves; j++)
		{
			if (v->current.deeper[i].deeper[j].rating == INT_MIN)
			{
				v->current.deeper[i].rating = INT_MIN;
				break ;
				
			}		
		}
	}

	//deze functie
	search_best_move(v);


	free_all_gamestates(v);
	v->end_of_turn = true;
	pthread_exit(NULL);
	return NULL;
}
