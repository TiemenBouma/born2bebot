#ifndef born2bebot_h
#define born2bebot_h

#include <stddef.h>
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define max_search_depth 3

enum e_color
{
	red,
	yellow,
	cyan,
	blue,
	magenta
};

enum e_move_type
{
	drop,
	rotate
	//fetch?
};

typedef enum e_gravity_direction
{
	top,
	top_right,
	bottom_right,
	bottom,
	bottom_left,
	top_left,
}	t_grav;

typedef struct s_my_chips_data
{
	int				choices;
	int				drawn_chips[2];			//the drawn chips for the next move
	enum e_color	chip_colors[2];			//the actual colors we play with
	int				played_chips[2];		//amount of chips we put on the hex, for each color
	int				discarded_chips[2];		//amount of chips we discarded with a rotate-move, for each color
	int				remaining_chips[2];		//amount of chips still in the bag, for each color
}	t_my_chips_data;

typedef struct s_opp_chips_data
{
	int				amount_knows_colors;
	enum e_color	chip_colors[2];
	int				played_chips;
	int				played_rotations;
	int				total_discarded_chips;
	int				remaining_chips;
}	t_opp_chips_data;

typedef struct s_chips_data
{
	t_my_chips_data		mine;
	t_opp_chips_data	opp;
}	t_chips_data;

typedef struct s_move
{
	enum e_move_type	type;		//drop or rotate
	int					column;		//drop: play in this column
	enum e_color		color;		//drop: play this color
	int					direction;	//rotate: direction of gravity
}	t_move;

typedef struct s_chip
{
	int		value;
	float	x, y;
	int		tile_index;
	bool	placed;
}	t_chip;

typedef struct s_tile t_tile;
struct s_tile
{
	t_tile*	neigh[6];
	t_chip	chip;
	bool	is_winning;
	bool	wall;
	int		q, r, s;
	float	x, y;
};

typedef struct s_gamestate t_gamestate;
struct s_gamestate
{
	t_tile*			tile;						//array of hexagon tiles
	t_grav			gravity;
	t_move			move;
	int				rating;
	int				amount_possible_moves;	
	t_gamestate*	deeper;						//next depth, array with size of amount_possible_moves

	// size_t			amount_legal_moves;		//the num of legal moves at this gamestate
	// t_move*			legal_moves;			//array of all legal moves;
	// t_gamestate*	potential_gamestate;	//array of potental gamestate, if a move was played
};

typedef struct s_gameinput
{
	int		total_number_of_colors;
	int		chips_per_color;
	int		grid_size;
	float	timeout;
	int		player_id;
	int		win_length;
	int		max_column;
	int		min_column;
	int		amount_of_tiles;
	int		amount_colors_per_player;
}	t_gameinput;

typedef struct s_vars
{
	volatile bool	end_of_turn;
	int				turn;			//keeps track of the amount of turns played in the game
	t_gameinput		gameinput;
	t_move			next_move;
	t_chips_data	chips_data;
	t_gamestate		current;
}	t_vars;

/*		functions	*/
void	init(t_vars *v);
void	input(t_vars *v);
void    *bot(void *ptr);

t_tile*	game_get(t_vars *v, t_gamestate *g, int q, int r, int s);
void 	compute_pos(int pos, int size, int gravity, int *q, int *r, int *s);

bool	process_move(t_vars *v, t_gamestate *g, t_move *m);
int		game_winner(t_vars *v, t_gamestate *g);
void	init_gamestate(t_vars *v, t_gamestate *g);
void	copy_gamestate(t_vars *v, t_gamestate *dst, t_gamestate *src);

/*		free.c	*/
void	free_gamestates(t_vars *v);

#endif
