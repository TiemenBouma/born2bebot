#include "born2bebot.h"

static void	free_gamestate(t_vars *v, t_gamestate *g)
{
	// dprintf(2, "g amnt poss moves = [%d]\n", g->amount_possible_moves);
	for (int i = 0; i < g->amount_possible_moves; ++i)
	{
		free_gamestate(v, &g->deeper[i]);
	}
	free(g->deeper);
	free(g->tile);
}

void	free_gamestates(t_vars *v)
{
	// dprintf(2, "v amnt poss moves = [%d]\n", v->current.amount_possible_moves);
	for (int i = 0; i < v->current.amount_possible_moves; ++i)
	{
		free_gamestate(v, &v->current.deeper[i]);
	}
	free(v->current.deeper);
}
