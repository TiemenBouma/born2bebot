#include "mcts.h"
#include "ft_loop.h"

t_mcts_node* mcts_node_new(const t_gamestate* game_state)
{
	t_mcts_node* node = malloc(sizeof(t_mcts_node));
	if (!node)
		return NULL;
	
	node->state = game_state;
	node->parent = NULL;
	node->player = 1;	// TODO: Get active player of game state

	node->children.count = ~0;	// Don't init children yet

	node->simulations = 0;
	node->score = 0;

	return node;
}

t_mcts_node* mcts_node_new_child(t_mcts_node* parent, const t_gamestate* game_state)
{
	t_mcts_node* node = malloc(sizeof(t_mcts_node));
	if (!node)
		return NULL;
	
	node->state = game_state;
	node->parent = parent;
	node->player = parent->player * -1;	// TODO: Get active player of game state

	node->children.count = ~0;	// Don't init children yet

	node->simulations = 0;
	node->score = 0;

	return node;
}

void mcts_node_free(t_mcts_node* node)
{
	list_foreach(&node->children, (t_foreach_value)mcts_node_free);
	free(node);
}

float mcts_node_get_weight(const t_mcts_node* node)
{
	const float exploration_parameter = 1.414f;
	// UCT: (Upper confidence bound)
    // wins / simulations + c * sqrt(ln(Parent Simulations) / simulations)

	return ((node->parent->player == node->player) ? 1 : -1) * node->score / (float)node->simulations
		+ exploration_parameter * sqrtf(logf(node->parent->simulations) / node->simulations);
}

t_move mcts_node_get_best_move(const t_mcts_node* node)
{
	const t_mcts_node* best_child = list_index(&node->children, 0);
	const t_mcts_node* curr_node = node;
	while (loop_l(&node->children, (void**)&curr_node))	// Loops through all nodes, skipping the first one
		if (curr_node->simulations > best_child->simulations)
			best_child = curr_node;
	return best_child->state->move;
}

void mcts_node_backpropegate(t_mcts_node* node, int add_score, int perspective, int simulations)
{
	node->simulations += simulations;
	node->score += (perspective == node->player) ? add_score : -add_score;

	if (node->parent)
		mcts_node_backpropegate(node->parent, add_score, perspective, simulations);
}

// Now the big part about mcts
t_mcts_node* mcts_node_select_child(t_mcts_node* node, const t_vars* v)
{
	if (node->simulations == 0)
		return node;
	if (game_winner(v, node->state))	// TODOOOOO: Cache variable, VERY IMPORTANT
		return node;
	
	if (node->children.count == ~0)	// Check if we have not yet initialized them
	{
		if (!list_init(&node->children, sizeof(t_mcts_node*)))
			return NULL;
		// TODO: Get possible moves & add them to children
	}

	// now we are sure that we need to make a choice between our children, and its not empty
	// if we have a child that has 0 simulations, select that one
	// otherwise, choose the child with the highest weight, gotten by mcts_node_get_weight

	t_mcts_node* best = NULL;
	float best_weight = -100000000;

	t_mcts_node* curr_node = NULL;
	while (loop_l(&node->children, (void**)&curr_node))	// Why must i cast C, why?
	{
		float weight = mcts_node_get_weight(curr_node);
		if (weight > best_weight)
		{
			best = curr_node;
			best_weight = weight;
		}
	}

	// NOTE: if best is NULL here, then there was no winner, but also no next moves
	return mcts_node_select_child(best, v);
}
