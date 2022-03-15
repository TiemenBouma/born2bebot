/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linked_list_new.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 15:07:56 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/01/26 17:37:03 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"
#include <stdlib.h>

t_linked_list	*linked_list_new(void *content)
{
	t_linked_list	*pt;

	pt = (t_linked_list *)malloc(sizeof(t_linked_list));
	if (pt == NULL)
		return (NULL);
	pt->content = content;
	pt->next = NULL;
	return (pt);
}
