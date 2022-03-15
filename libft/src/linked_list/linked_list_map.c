/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linked_list_map.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 15:29:08 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/01/26 17:36:56 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"
#include <stddef.h>

t_linked_list	*linked_list_map(t_linked_list *lst,
	void *(*f)(void *), void (*del)(void *))
{
	t_linked_list	*new;
	t_linked_list	*current;

	new = NULL;
	while (lst)
	{
		if (f != NULL)
			current = linked_list_new((*f)(lst->content));
		else
			current = linked_list_new(NULL);
		if (current == NULL)
		{
			linked_list_clear(&new, del);
			return (NULL);
		}
		linked_list_add_back(&new, current);
		lst = lst->next;
	}
	return (new);
}
