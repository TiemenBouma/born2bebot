#include "born2bebot.h"

t_tile*	game_get(t_vars *v, t_gamestate *g, int q, int r, int s)
{
	t_tile* t;

	for (int i = 0; i < v->gameinput.amount_of_tiles; i += 1)
	{
		t = &g->tile[i];
		if (t->q == q && t->r == r && t->s == s)
			return t;
	}
	return NULL;
}

void    assign_neigh(t_tile* tiles, t_tile* dest, t_tile* src, size_t neigh_index)
{
    if (!src->neigh[neigh_index])
	{
        dest->neigh[neigh_index] = NULL;
        return;
    }
    size_t index = src->neigh[neigh_index]->index;
    dest->neigh[neigh_index] = &tiles[index];
}

static void copy_neigh(t_vars* v, t_gamestate *dest, t_gamestate* src)
{
    for (int i = 0; i < v->gameinput.amount_of_tiles; i++) 
	{
        t_tile* tile = &dest->tile[i];
        for (size_t neigh = 0; neigh < 6; neigh++) {
            assign_neigh(dest->tile, tile, &src->tile[i], neigh);
        }
    }
}

static void init_neigh(t_vars *v, t_gamestate *g)
{
	for (int i = 0; i < v->gameinput.amount_of_tiles; i += 1)
	{
		t_tile* dt = &g->tile[i];
		dt->index = i;
		dt->neigh[0] = game_get(v, g, dt->q, dt->r - 1, dt->s + 1);
		dt->neigh[1] = game_get(v, g, dt->q + 1, dt->r - 1, dt->s);
		dt->neigh[2] = game_get(v, g, dt->q + 1, dt->r, dt->s - 1);
		dt->neigh[3] = game_get(v, g, dt->q, dt->r + 1, dt->s - 1);
		dt->neigh[4] = game_get(v, g, dt->q - 1, dt->r + 1, dt->s);
		dt->neigh[5] = game_get(v, g, dt->q - 1, dt->r, dt->s + 1);
	}
}

static void coord_convert(float *x, float *y, int q, int r, int s)
{
	(void) s;
	*x = q * sqrt(3) / 2;
	*y = (int) (r + (q - (q & 1)) / 2) + (q & 1) * 0.5f;
}

static void	init_tiles(t_vars *v, t_gamestate *g)
{
	g->tile = calloc(v->gameinput.amount_of_tiles, sizeof(t_tile));
	int	i = 0;

	for (int q = -v->gameinput.grid_size + 1; q < v->gameinput.grid_size; q += 1)
	{
		for (int r = -v->gameinput.grid_size + 1; r < v->gameinput.grid_size; r += 1)
		{
			for (int s = -v->gameinput.grid_size + 1; s < v->gameinput.grid_size; s += 1)
			{
				if (q + r + s == 0)
				{
					t_tile* t = &g->tile[i];
					t->q = q;
					t->r = r;
					t->s = s;
					t->wall = false;
					coord_convert(&t->x, &t->y, q, r, s);
					t->chip.value = -1;
					t->chip.tile_index = -1;
					t->chip.placed = false;
					t->chip.x = t->x;
					t->chip.y = t->y;
					t->index = i;
					i += 1;
				}
			}
		}
	}
}

static void    copy_tiles(t_vars *v, t_gamestate *g, t_gamestate *src)
{
    g->tile = malloc(v->gameinput.amount_of_tiles * sizeof(t_tile));
    memcpy(g->tile, src->tile, sizeof(t_tile) * v->gameinput.amount_of_tiles);
}

void	init_gamestate(t_vars *v, t_gamestate *g)
{
	init_tiles(v, g);
	init_neigh(v, g);
	v->current.gravity = bottom;
}
void	copy_gamestate(t_vars *v, t_gamestate *dst, t_gamestate *src)
{
	copy_tiles(v, dst, src);
	copy_neigh(v, dst, src);
	dst->gravity = src->gravity;
}

static void	get_gameinput(t_gameinput *g)
{
	scanf("init %d %d %d %d %f %d",	&g->total_number_of_colors, \
									&g->chips_per_color, \
									&g->grid_size, \
									&g->win_length, \
									&g->timeout, \
									&g->player_id);
}

void	init(t_vars *v)
{
	bzero(v, sizeof(t_vars));
	setbuf(stdout, NULL);
	setbuf(stdin, NULL);
	setbuf(stderr, NULL);
	get_gameinput(&v->gameinput);
	v->chips_data.opp.remaining_chips = 2 * v->gameinput.chips_per_color;
	v->gameinput.max_column = v->gameinput.grid_size - 1;
	v->gameinput.min_column = -v->gameinput.max_column;
	v->gameinput.amount_of_tiles = 3 * pow(v->gameinput.grid_size, 2) - 3 * v->gameinput.grid_size + 1;
	v->gameinput.amount_colors_per_player = v->gameinput.total_number_of_colors / 2;
	init_gamestate(v, &v->current);
}
