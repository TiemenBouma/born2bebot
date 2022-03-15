/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_un_init.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jasper <jasper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/23 11:57:46 by jasper        #+#    #+#                 */
/*   Updated: 2021/04/17 12:03:46 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>
#include "libft.h"
//#include <stdio.h>

void	list_un_init(t_list *list, const t_free_values free_values)
{
	size_t	i;

	if (free_values)
	{
		i = 0;
		while (i < list->count)
		{
			(*free_values)(list->data + list->data_size * i);
			i++;
		}
	}
	free(list->data);
}

void	list_free(t_list *list, const t_free_values free_values)
{
	list_un_init(list, free_values);
	free(list);
}
