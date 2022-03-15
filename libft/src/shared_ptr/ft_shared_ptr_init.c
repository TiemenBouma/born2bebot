/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_shared_ptr8_init.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/28 19:04:14 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/02/05 13:47:10 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shared_ptr.h"
#include <stdlib.h>

void	shared_pt_init(t_shared_pt *ptr, void *data,
	t_free_func free_ptr)
{
	ptr->count = 1;
	ptr->ptr = data;
	ptr->free_ptr = free_ptr;
}

t_shared_pt	*shared_pt_new(void *data, t_free_func free_ptr)
{
	t_shared_pt	*ptr;

	ptr = malloc(sizeof(t_shared_pt));
	if (ptr == NULL)
		return (NULL);
	shared_pt_init(ptr, data, free_ptr);
	return (ptr);
}

void	shared_pt_un_init(t_shared_pt *ptr)
{
	ptr->free_ptr(ptr->ptr);
	ptr->count = 0;
}

void	shared_pt_free(t_shared_pt *ptr)
{
	shared_pt_un_init(ptr);
	free(ptr);
}
