/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linked_list_clear.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 15:21:15 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/01/26 17:36:51 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"
#include <stdlib.h>

void	linked_list_clear(t_linked_list **lst, void (*del)(void*))
{
	t_linked_list	*to_free;

	while (*lst)
	{
		to_free = *lst;
		if (del != NULL)
			(*del)((*lst)->content);
		*lst = (*lst)->next;
		free(to_free);
	}
	*lst = NULL;
}
