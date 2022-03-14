#ifndef timer_h
#define timer_h

#include <sys/time.h>
#include <stddef.h>
#include <stdbool.h>

#define one_million 1000000

typedef struct s_timer
{
	struct timeval	current_time;
	size_t			start_s;
	size_t			start_us;
	size_t			elapsed_s;
	size_t			elapsed_us;
	size_t			timestamp;
}	t_timer;

/*		functions	*/
void	timer(float timeout, volatile const bool* const end_of_turn);

#endif
