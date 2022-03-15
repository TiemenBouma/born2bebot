/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_init.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 12:16:27 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/04/05 16:44:09 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INIT_H
# define FT_INIT_H

# include <stdbool.h>
# include <stddef.h>

/*
**	I had so manny: init this, if not success, free previous stuff
**	And the free previous stuff was just getting out of hand
**	alot of copy pasting there
**	So i made this helper function that handles it for me. :D
*/

struct			s_init_data;

typedef bool	(*t_init_func)(struct s_init_data *init_data);
typedef void	(*t_free_func)(struct s_init_data *init_data);

typedef struct s_init_data
{
	t_init_func	init_func;
	t_free_func	free_func;
	char		*error_msg;
	void		*data;
}				t_init_data;

/*
**	on success, this function returns 0
**	on error, this function returns the ~ of the index that failed to init
**		example usage:
**		int err_index = init_values(...)
**		if (err_index)
**			printf("Index %i failed to initialize!\n", ~err_index);
*/

int				init_values(int num_values, t_init_data *data);
void			free_values(int num_values, t_init_data *data);
t_init_data		init_data_create(t_init_func init_func,
					t_free_func	free_func, void *data, char *error_msg);

/*
**	Commonly used init types
*/

bool			init_fail(t_init_data *init_data);

typedef struct s_init_data_malloc
{
	void	**value_loc;
	size_t	size;
}				t_init_data_malloc;

typedef struct s_init_data_open
{
	int			*fd_loc;
	const char	*file;
	int			o_flag;
}				t_init_data_open;

t_init_data		init_data_create_malloc(void *value_loc, size_t size,
					char *error_msg);
t_init_data		init_data_create_open(int *fd_loc, const char *file,
					int o_flag, char *error_msg);

#endif
