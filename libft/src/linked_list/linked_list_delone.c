/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linked_list_delone.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 15:19:11 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/01/26 17:37:18 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"
#include <stdlib.h>

void	linked_list_delone(t_linked_list *lst, void (*del)(void*))
{
	if (lst == NULL)
		return ;
	if (del != NULL)
		(*del)(lst->content);
	free(lst);
}
