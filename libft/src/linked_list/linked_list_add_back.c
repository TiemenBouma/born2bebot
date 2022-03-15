/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linked_list_add_back.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 15:16:51 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/01/26 17:37:22 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"
#include <stddef.h>

void	linked_list_add_back(t_linked_list **lst, t_linked_list *new)
{
	if (*lst == NULL)
		*lst = new;
	else
		linked_list_last(*lst)->next = new;
}
