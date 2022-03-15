/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_init_mutex_attr.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 12:55:11 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/02/11 11:39:05 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_init_create_threading.h"
#include <stdlib.h>

static bool	init_mutex(t_init_data *init_data)
{
	t_init_data_mutex_attr	mutex_data;

	mutex_data = *(t_init_data_mutex_attr *)init_data->data;
	free(init_data->data);
	init_data->data = mutex_data.mutex;
	return (pthread_mutex_init(mutex_data.mutex, mutex_data.attr) == 0);
}

static void	free_mutex(t_init_data *init_data)
{
	pthread_mutex_destroy(init_data->data);
}

t_init_data	init_data_create_mutex_attr(pthread_mutex_t *mutex,
	const pthread_mutexattr_t *attr, char *error_msg)
{
	t_init_data_mutex_attr	*mutex_attr_data;

	mutex_attr_data = malloc(sizeof(t_init_data_mutex_attr));
	if (!mutex_attr_data)
		return (init_data_create(init_fail, NULL, NULL, error_msg));
	mutex_attr_data->mutex = mutex;
	mutex_attr_data->attr = attr;
	return (init_data_create(init_mutex,
			free_mutex, mutex_attr_data, error_msg));
}
