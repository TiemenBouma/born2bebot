/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linked_list_add_front.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 15:11:54 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/01/26 17:37:20 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"
#include <stddef.h>

void	linked_list_add_front(t_linked_list **lst, t_linked_list *new)
{
	if (new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}
