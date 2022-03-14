#include <sys/time.h>
#include <unistd.h>
#include <string.h>
#include "timer.h"
#include "born2bebot.h"

static void	update_elapsed_time(t_timer *t, size_t time_limit_in_us)
{
	gettimeofday(&t->current_time, NULL);
	t->elapsed_us = t->current_time.tv_usec - t->start_us;
	t->elapsed_s = t->current_time.tv_sec - t->start_s;
	if (t->elapsed_s > 0)
		t->elapsed_us += (t->elapsed_s * time_limit_in_us);
}

void	timer(float timeout, volatile const bool* const end_of_turn)
{
	const size_t	nappytime = 100;
	const size_t	time_limit_in_us = timeout * one_million;
	t_timer			t;

	bzero(&t, sizeof(t));
	gettimeofday(&t.current_time, NULL);
	t.start_s = t.current_time.tv_sec;
	t.start_us = t.current_time.tv_usec;
	while (t.elapsed_us + nappytime < time_limit_in_us)
	{
		if (*end_of_turn == true)
			return;
		usleep(nappytime);
		update_elapsed_time(&t, time_limit_in_us);
	}
	dprintf(2, "---- time's up! A move has to be made now...\n");
	dprintf(2, "time elapsed (us): [%lu] / [%lu]\n", t.elapsed_us, time_limit_in_us);
}
