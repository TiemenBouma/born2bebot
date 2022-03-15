/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_init_mutex.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 12:55:11 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/02/11 11:35:13 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_init_create_threading.h"

static bool	init_mutex(t_init_data *init_data)
{
	return (pthread_mutex_init(init_data->data, NULL) == 0);
}

static void	free_mutex(t_init_data *init_data)
{
	pthread_mutex_destroy(init_data->data);
}

t_init_data	init_data_create_mutex(pthread_mutex_t *mutex, char *error_msg)
{
	return (init_data_create(init_mutex, free_mutex, mutex, error_msg));
}
