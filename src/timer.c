#include <sys/time.h>
#include <unistd.h>
#include <string.h>
#include "timer.h"
#include "born2bebot.h"


int    get_elapsed_time(struct timeval* result, struct timeval* x, struct timeval* y)
{
    // preserve *y
    struct timeval yy = *y;
    y = &yy;

    /* Perform the carry for the later subtraction by updating y. */  
    if (x->tv_usec < y->tv_usec) {  
        int nsec = (y->tv_usec - x->tv_usec) / one_million + 1;  
        y->tv_usec -= one_million * nsec;  
        y->tv_sec += nsec;  
    }  
    if (x->tv_usec - y->tv_usec > one_million) {  
        int nsec = (y->tv_usec - x->tv_usec) / one_million;  
        y->tv_usec += one_million * nsec;  
        y->tv_sec -= nsec;  
    }  
    /* Compute the time remaining to wait.
        tv_usec is certainly positive. */  
    result->tv_sec = x->tv_sec - y->tv_sec;  
    result->tv_usec = x->tv_usec - y->tv_usec;  

    /* Return 1 if result is negative. */  
    return x->tv_sec < y->tv_sec;  
}

void	timer(float timeout, volatile const bool* const end_of_turn)
{
	const size_t	time_limit_in_us = timeout * one_million * 0.95;
	struct timeval	start;
	struct timeval	current;
	struct timeval	diff;

	gettimeofday(&start, NULL);
    size_t elapsed_us = 0;
 
    while (elapsed_us < time_limit_in_us)
    {
		if (*end_of_turn == true)
			break;
        gettimeofday(&current, NULL);
        get_elapsed_time(&diff, &current, &start);
        elapsed_us = diff.tv_sec * one_million + diff.tv_usec;
    }
	dprintf(2, "time elapsed (us): [%lu] / [%lu]\n", elapsed_us, time_limit_in_us);
}
