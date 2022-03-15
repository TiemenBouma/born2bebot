/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_clear.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/05 16:33:46 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/02/06 13:06:32 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	list_clear(t_list *list, const t_free_values free_values)
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
	list->count = 0;
}
