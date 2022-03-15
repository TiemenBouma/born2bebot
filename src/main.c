#include "born2bebot.h"
#include "utils.h"
#include "timer.h"

void	start_search_thread(pthread_t *thread_id, t_vars *v)
{
	// dprintf(2, "---- start a search thread\n");
	v->end_of_turn = false;
	pthread_create(thread_id, NULL, &bot, v);
}

void	cancel_search_thread(pthread_t *thread_id, t_vars *v)
{
	// dprintf(2, "---- cancel the search thread\n");
	pthread_cancel(*thread_id);
	v->end_of_turn = true;
}

void	output(t_move* next_move)
{
	switch (next_move->type)
	{
		case drop:
			// dprintf(2, "drop %d %d\n", next_move->column, next_move->color);
			printf("drop %d %d\n", next_move->column, next_move->color);
			break;
		case rotate:
			// dprintf(2, "rotate %d\n", next_move->direction);
			printf("rotate %d\n", next_move->direction);
			break;
	}
}

void	update_chips_data(t_my_chips_data *mine, t_move *m)
{
	//we got nothing here so far
	switch (m->type)
	{
		case drop:
			break;
		case rotate:
			break;
	}
}

void	increment_game_turn(int* const turn)
{
	*turn += 1;
	// dprintf(2, "turn is now: [%d]\n", *turn);
}

void	set_preferred_color(enum e_color color)
{
	printf("color %d\n", color);
}

int main()
{
	t_vars		v;
	pthread_t	search_thread;;

	init(&v);
	set_preferred_color(magenta);
	while (true)
	{
		input(&v);
		start_search_thread(&search_thread, &v);
		timer(v.gameinput.timeout, &v.end_of_turn);
		cancel_search_thread(&search_thread, &v);
		output(&v.next_move);
		if (process_move(&v, &v.current, &v.next_move))
			break;
		update_chips_data(&v.chips_data.mine, &v.next_move);
		increment_game_turn(&v.turn);
	}
	return 0;
}
