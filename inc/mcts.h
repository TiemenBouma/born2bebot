#ifndef mcts_h
#define mcts_h

#include "born2bebot.h"
#include <ft_list.h>

// Can be pretty much anything, aslong as it gives on average a good estimate of who is winning
//	Can even be something as simple as a play random untill someone wins
typedef int (*t_playout_func)(t_gamestate* game_state);

typedef struct
{
	t_gamestate* state;
	t_mcts_node* parent;

	int player;
	t_list children;	// list<t_mcts_node*>

	int simulations;
	int score;
} t_mcts_node;

typedef struct
{
	t_mcts_node* base_node;
	t_playout_func playout_func;
} t_mcts;

// mcts
t_mcts* mcts_new(t_gamestate* game_state, t_playout_func playout_func);
void mcts_free(t_mcts * mcts);

void mcts_do_iteration(t_mcts * mcts);
t_move mcts_get_best_move(const t_mcts * mcts);

// mcts_node
t_mcts_node* mcts_node_new(t_gamestate* game_state);
t_mcts_node* mcts_node_new_child(t_mcts_node* parent, int player);

void mcts_node_free(t_mcts_node* node);

void mcts_node_backpropegate(t_mcts_node* node, int add_score, int perspective, int simulations);
t_mcts_node* mcts_node_select_child(t_mcts_node* node);

#endif