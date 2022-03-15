#ifndef mcts_h
#define mcts_h

#include "born2bebot.h"
#include <ft_list.h>

typedef struct
{
	
} t_mcts;

typedef struct
{

} t_mcts_node;


void mcts_do_iteration(t_mcts * mcts);
t_move mcts_get_best_move(const t_mcts * mcts);

#endif