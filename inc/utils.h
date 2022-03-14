#ifndef utils_h
#define utils_h

#include "born2bebot.h"

int     max(int a, int b);
int     min(int a, int b);
bool	is_my_color(t_gameinput *g, int value);
bool	is_opp_color(t_gameinput *g, int value);
bool	is_empty(t_vars *v, t_gamestate *g, int col);

#endif
