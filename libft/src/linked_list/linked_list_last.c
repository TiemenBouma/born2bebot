/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linked_list_last.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 15:15:24 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/01/26 17:37:14 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"
#include <stddef.h>

t_linked_list	*linked_list_last(t_linked_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (true)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
}
