#include <stdbool.h>
#include "born2bebot.h"

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}

bool	is_my_color(t_gameinput *g, int value)
{
	if (value < 0)
		return false;
	if (g->player_id == 0)
	{
		return value < g->total_number_of_colors / 2;
	}
	return value >= g->total_number_of_colors / 2;
}

bool	is_opp_color(t_gameinput *g, int value)
{
	if (value < 0)
		return false;
	if (g->player_id == 1)
	{
		return value < g->total_number_of_colors / 2;
	}
	return value >= g->total_number_of_colors / 2;
}

bool	is_empty(t_vars *v, t_gamestate *g, int col)
{
	int q, r, s;

	compute_pos(col, v->gameinput.grid_size, g->gravity, &q, &r, &s);
	t_tile *t = game_get(v, g, q, r, s);
	return t->chip.value == -1;
}
