#include "born2bebot.h"

int find_comb(const t_vars *v, const t_gamestate *g, int comb)
{
	int best_length = 0;
	int best_value = -1;
	int best_count = 0;
	int best_index = -1;
	int best_direction = -1;

	for (int dir = 0; dir < 3; dir += 1)
	{
		for (int i = 0; i <  v->gameinput.amount_of_tiles; i += 1)
		{
			int length = 0;
			int value = g->tile[i].chip.value;
			if (value == -1)
				continue;
			t_tile* t = &g->tile[i];
			while (t != NULL && t->chip.value == value)
			{
				length += 1;
				t = t->neigh[dir];
			}
			if (length > best_length)
			{
				best_length = length;
				best_value = value;
				best_count = 1;
				best_index = i;
				best_direction = dir;
			}
			else if (length == best_length && best_value * 2 / v->gameinput.amount_colors_per_player != value * 2 / v->gameinput.amount_colors_per_player)
				best_count += 1;
		}
	}
	if (best_length >= comb && best_count == 1)
	{
		t_tile* t = &g->tile[best_index];
		for (int i = 0; i < best_length; i++)
		{
			t->is_winning = true;
			t = t->neigh[best_direction];
		}
		return best_value;
	}
	return -1;
}
