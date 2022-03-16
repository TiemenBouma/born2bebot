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



int get_opposite_direction(const int dir) {
	return (dir + 3) % 6;
}

int neighbour_colour_check(const t_tile *current_tile, int direction)
{
	if (current_tile->neigh[direction]) {
		if (current_tile->chip.value == current_tile->neigh[direction]->chip.value)
			return (1);
	}
	return (0);
}

int direction_check(const t_tile *current_tile, int direction)
{
	int	number_of_same_tiles = 0;
	
	while (current_tile && neighbour_colour_check(current_tile, direction))
	{
		number_of_same_tiles++;
		current_tile = current_tile->neigh[direction];
	}
	return (number_of_same_tiles);
}

//Als we de wincheck sneller willen maken moeten we een pointer 
//van de laatst gedropte tile weten en die kunnenw e in deze functie toevoegen
int	win_check_this_tile(const t_tile *current_tile, int win_length) 
{
	int direction = 0;	
	
	while (direction < 3) {
		int nb = 1 + direction_check(current_tile, direction) +
				direction_check(current_tile, get_opposite_direction(direction));
		if (nb >= win_length) {
			// 4 in a row, there is a winner!
			return (current_tile->chip.value);			
		}
		direction++;
	}
	return (0);
}
