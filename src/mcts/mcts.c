#include "mcts.h"

// mcts
t_mcts* mcts_new(const t_gamestate* game_state, t_playout_func playout_func)
{
	t_mcts* ptr = malloc(sizeof(t_mcts));
	if (!ptr)
		return NULL;

	ptr->base_node = mcts_node_new(game_state);
	if (!ptr->base_node)
	{
		free(ptr);
		return NULL;
	}
	ptr->playout_func = playout_func;

	return ptr;
}

void mcts_free(t_mcts* mcts)
{
	mcts_node_free(mcts->base_node);
	free(mcts);
}

void mcts_do_iteration(t_mcts* mcts, const t_vars* v)
{
	t_mcts_node* child = mcts_node_select_child(mcts->base_node, v);

	int score = mcts->playout_func(child->state);

	mcts_node_backpropegate(child, score, child->player, 1);	// TODO: Double check that playout func returns a score for this player
}

t_move mcts_get_best_move(const t_mcts* mcts)
{
	return mcts_node_get_best_move(mcts->base_node);
}