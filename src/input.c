#include "born2bebot.h"

static void	draw_chips_from_bag(t_my_chips_data *mine)
{
	scanf("chips %d %d", &mine->drawn_chips[0], &mine->drawn_chips[1]);

	if (mine->drawn_chips[0] != mine->drawn_chips[1])
	{
		if (mine->drawn_chips[1] != -1)
			mine->choices = 2;
		else
			mine->choices = 1;
	}
	else
		mine->choices = 1;
}

static void	update_opponent_chips_data(t_opp_chips_data *d, t_move *m)
{
	switch (m->type)
	{
		case drop:
			d->played_chips++;
			d->remaining_chips -= 1;
			break;

		case rotate:
			d->played_rotations++;
			d->total_discarded_chips += 2;
			d->remaining_chips -= 2;
			break;
	}
}

static t_move	get_opponent_move()
{
	t_move	move;
	char	move_type[32];

	bzero(&move, sizeof(t_move));
	scanf("%s", move_type);
	if (!strcmp(move_type, "drop"))
	{
		move.type = drop;
		scanf("%d %d\n", &move.column, (int*)&move.color);
		// dprintf(2, "opp played: drop %d %d\n", move.column, move.color); //debug
	}
	else if (!strcmp(move_type, "rotate"))
	{
		move.type = rotate;
		scanf("%d\n", &move.direction);
		// dprintf(2, "opp played: rotate %d\n", move.direction);	//debug
	}
	else
	{
		// dprintf(2, "exit: game over\n");
		exit(EXIT_FAILURE);
	}
	return move;
}

void	normal_move(t_vars *v)
{
	t_move opponent_move = get_opponent_move();
	update_opponent_chips_data(&v->chips_data.opp, &opponent_move);
	if (process_move(v, &v->current, &opponent_move))
		exit(EXIT_SUCCESS);
}

void	input(t_vars *v)
{
	switch (v->gameinput.player_id)
	{
		case 0:
			if (!v->turn)
				scanf("\n");
			else
				normal_move(v);
			break;

		case 1:
			normal_move(v);
			break;
	}
	draw_chips_from_bag(&v->chips_data.mine);
}
