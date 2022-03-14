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
	if (g->player_id == 0)
	{
		return value < g->total_number_of_colors / 2;
	}
	return value >= g->total_number_of_colors / 2;
}
