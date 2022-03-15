/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linked_list_iter.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 15:26:51 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/01/26 17:37:16 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"
#include <stddef.h>

void	linked_list_iter(t_linked_list *lst, void (*f)(void *))
{
	if (f == NULL)
		return ;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
