/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_init_open.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 12:50:05 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/02/11 11:39:17 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_init.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/*
** currently guesstimating the mode that you want to use
** not enough arguments per function for easy use :(
*/

static bool	init_open(t_init_data *init_data)
{
	t_init_data_open	*open_data;
	int					*fd_loc;

	open_data = init_data->data;
	fd_loc = open_data->fd_loc;
	*fd_loc = open(open_data->file, open_data->o_flag,
			S_IWUSR | S_IRUSR);
	free(init_data->data);
	init_data->data = fd_loc;
	if (*fd_loc < 0)
		return (false);
	return (true);
}

static void	free_open(t_init_data *init_data)
{
	int	*fd_loc;

	fd_loc = init_data->data;
	close(*fd_loc);
}

t_init_data	init_data_create_open(int *fd_loc, const char *file, int o_flag,
	char *error_msg)
{
	t_init_data_open	*store_data;

	store_data = malloc(sizeof(t_init_data_open));
	if (!store_data)
		return (init_data_create(init_fail, NULL, NULL, error_msg));
	store_data->fd_loc = fd_loc;
	store_data->file = file;
	store_data->o_flag = o_flag;
	return (init_data_create(init_open, free_open, store_data, error_msg));
}
