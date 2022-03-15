/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_access.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/03 12:28:48 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/05/17 14:44:25 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_list.h"

bool	list_push(t_list *list, const void *value)
{
	if (list->count == list->capacity
		&& !list_set_capacity(list, list->capacity * 2))
		return (false);
	ft_memcpy(list->data + list->data_size * list->count,
		value, list->data_size);
	list->count++;
	return (true);
}

void	*list_pop(t_list *list)
{
	void	*ret;

	if (list->count == 0)
		return (NULL);
	ret = list_index(list, list->count - 1);
	list->count--;
	return (ret);
}

// Used when inserting a already existing variable into a list
static bool	re_insert(t_list *list, size_t index, const void *value)
{
	void	*location;
	size_t	prev_index;

	prev_index = list_reverse_index_unchecked(list, value);
	if (list->count == list->capacity
		&& !list_set_capacity(list, list->capacity * 2))
		return (false);
	location = list->data + index * list->data_size;
	ft_memmove(location + list->data_size, location,
		list->data_size * (list->count - index));
	if (prev_index >= index)
		prev_index++;
	ft_memcpy(location, list_index_unchecked(list, prev_index),
		list->data_size);
	list->count++;
	return (true);
}

bool	list_insert(t_list *list, size_t index, const void *value)
{
	void	*location;

	if (index > list->count)
		return (false);
	if (list_contains(list, value))
		return (re_insert(list, index, value));
	if (list->count == list->capacity
		&& !list_set_capacity(list, list->capacity * 2))
		return (false);
	location = list->data + index * list->data_size;
	ft_memmove(location + list->data_size, location,
		list->data_size * (list->count - index));
	ft_memcpy(location, value, list->data_size);
	list->count++;
	return (true);
}

bool	list_remove(t_list *list, size_t index)
{
	void	*location;

	if (index >= list->count)
		return (false);
	location = list->data + index * list->data_size;
	ft_memmove(location, location + list->data_size,
		list->data_size * (list->count - index - 1));
	list->count--;
	return (true);
}
