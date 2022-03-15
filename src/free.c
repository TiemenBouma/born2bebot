#include "born2bebot.h"

void	free_gamestate(t_vars *v, t_gamestate *g)
{
	for (int i = 0; i < g->amount_possible_moves; ++i)
	{
		free_gamestate(v, &g->deeper[i]);
	}
	free(g->deeper);
	free(g->tile);
	g->deeper = NULL;
	g->tile = NULL;
	g->amount_possible_moves = 0;
}

void	free_all_gamestates(t_vars *v)
{
	for (int i = 0; i < v->current.amount_possible_moves; ++i)
	{
		free_gamestate(v, &v->current.deeper[i]);
	}
	free(v->current.deeper);
	v->current.amount_possible_moves = 0;
	v->current.deeper = NULL;
}
