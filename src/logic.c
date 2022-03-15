#include "born2bebot.h"

t_tile*	game_update(t_vars *v, t_gamestate *g, t_tile *t)
{
	t_tile *next = t->neigh[g->gravity];
	t_chip	chip_data;
	if (next == NULL && t->chip.value == -1)
		return t;
	if (next == NULL)
		return t->neigh[(g->gravity + 3) % 6];
	t_tile* dropped = game_update(v, g, next);
	if (t->chip.value == -1)
		return dropped;
	chip_data = t->chip;
	t->chip = dropped->chip;
	dropped->chip = chip_data;
	return dropped->neigh[(g->gravity + 3) % 6];
}

static void game_rotate(t_vars *v, t_gamestate *g, int gravity)
{
	g->gravity = gravity;
	for (int i = 0; i < v->gameinput.amount_of_tiles; i++)
	{
		game_update(v, g, &g->tile[i]);
	}
}

static void game_drop(t_vars *v, t_gamestate *g, int q, int r, int s, int value)
{
	t_tile* t = game_get(v, g, q, r, s);
	if (!t)
	{
		dprintf(2, "[%p]\n", (void*)t);
		
		dprintf(2, "[%d][%d][%d]\n", q, r, s);
		exit(0);
		return;
	}
	t->chip.value = value;
	t->chip.x = t->x;
	t->chip.y = t->y;
	game_update(v, g, t);
}

void compute_pos(int pos, int size, int gravity, int *q, int *r, int *s)
{
	size -= 1;
	*q = pos;
	if (pos < 0) {
		*r = -size - pos;
		*s = size;
	} else {
		*r = -size;
		*s = size - pos;
	}
	while (gravity > -3)
	{
		int tmp = *q;
		*q = -*r;
		*r = -*s;
		*s = -tmp;
		gravity -= 1;
	}
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
	
	while (current_tile && neighbour_colour_check(current_tile, direction)) {
		number_of_same_tiles++;
		current_tile = current_tile->neigh[direction];
	}
	return (number_of_same_tiles);
}

//Als we de wincheck sneller willen maken moeten we een pointer 
//van de laatst gedropte tile weten en die kunnenw e in deze functie toevoegen
int	win_check_this_tile(const t_tile *current_tile, int win_length) {
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

int	win_check_all_tiles(t_vars *v, t_gamestate *g) {
	//int i = 0;
	for (int i = 0; i <  v->gameinput.amount_of_tiles; i += 1)
	{
		int value = g->tile[i].chip.value;
		if (value == -1)
			continue;
		if (g->tile[i].chip.value) {
			if (win_check_this_tile(&g->tile[i], v->gameinput.win_length))
				return (g->tile[i].chip.value);
		}
	}
	return (-1);
}

// int game_winner(t_vars *v, t_gamestate *g)
// {
// 	int best_length = 0;
// 	int best_value = -1;
// 	int best_count = 0;
// 	int best_index = -1;
// 	int best_direction = -1;

// 	for (int i = 0; i <  v->gameinput.amount_of_tiles; i += 1)
// 	{
// 		int length = 0;
// 		int value = g->tile[i].chip.value;
// 		if (value == -1)
// 			continue;
// 		t_tile* t = &g->tile[i];
// 		while (t != NULL && t->chip.value == value)
// 		{
// 			for (int dir = 0; dir < 3; dir += 1)
// 			{
// 				length += 1;
// 				t = t->neigh[dir];
// 			}
// 		}
// 		if (length > best_length)
// 		{
// 			best_length = length;
// 			best_value = value;
// 			best_count = 1;
// 			best_index = i;
// 			best_direction = dir;
// 		}
// 		else if (length == best_length && best_value * 2 / v->gameinput.amount_colors_per_player != value * 2 / v->gameinput.amount_colors_per_player)
// 			best_count += 1;
// 	}
// 	if (best_length >= v->gameinput.win_length && best_count == 1)
// 	{
// 		t_tile* t = &g->tile[best_index];
// 		for (int i = 0; i < best_length; i++)
// 		{
// 			t->is_winning = true;
// 			t = t->neigh[best_direction];
// 		}
// 		return best_value;
// 	}
// 	return -1;
// }


bool	game_end(t_vars *v)
{
	int ret_winner = win_check_all_tiles(v, &v->current);
	if (ret_winner != -1)
	{
		return true;
	}
	return false;
}

bool	process_move(t_vars *v, t_gamestate *g, t_move *m)
{
	int q, r, s;

	switch (m->type)
	{
		case drop:
			compute_pos(m->column, v->gameinput.grid_size, g->gravity, &q, &r, &s);
			game_drop(v, g, q, r, s, m->color);
			break;

		case rotate:
			game_rotate(v, g, m->direction);
			break;
	}
	return (game_end(v));
}
