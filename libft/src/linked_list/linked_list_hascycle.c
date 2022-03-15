/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linked_list_hascycle.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 12:45:11 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/01/26 17:36:58 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"
#include <stddef.h>

bool	linked_list_hascycle(t_linked_list *lst)
{
	t_linked_list	*fast;
	t_linked_list	*slow;

	fast = lst;
	slow = lst;
	while (fast->next)
	{
		fast = fast->next;
		slow = slow->next;
		if (fast->next == NULL)
			break ;
		fast = fast->next;
		if (fast == slow)
			return (true);
	}
	return (false);
}
