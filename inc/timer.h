#ifndef timer_h
#define timer_h

#include <sys/time.h>
#include <stddef.h>
#include <stdbool.h>

#define one_million 1000000

void	timer(float timeout, volatile const bool* const end_of_turn);

#endif
