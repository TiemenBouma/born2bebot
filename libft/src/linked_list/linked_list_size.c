/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linked_list_size.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 15:13:53 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/01/26 17:37:07 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"
#include <stddef.h>

int	linked_list_size(t_linked_list *lst)
{
	int	len;

	len = 0;
	while (lst != NULL)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
