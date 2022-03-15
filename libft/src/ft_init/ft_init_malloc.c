/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_init_malloc.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 12:50:05 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/02/11 11:28:51 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_init.h"
#include <stdlib.h>

static bool	init_malloc(t_init_data *init_data)
{
	t_init_data_malloc	*malloc_data;
	void				*malloc_result;

	malloc_data = init_data->data;
	malloc_result = malloc(malloc_data->size);
	*(malloc_data->value_loc) = malloc_result;
	init_data->data = malloc_result;
	free(malloc_data);
	return (malloc_result != NULL);
}

static void	free_malloc(t_init_data *init_data)
{
	free(init_data->data);
}

t_init_data	init_data_create_malloc(
void *value_loc, size_t size, char *error_msg)
{
	t_init_data_malloc	*malloc_data;

	malloc_data = malloc(sizeof(t_init_data_malloc));
	if (!malloc_data)
		return (init_data_create(init_fail, NULL, NULL, error_msg));
	malloc_data->size = size;
	malloc_data->value_loc = value_loc;
	return (init_data_create(init_malloc, free_malloc, malloc_data, error_msg));
}
