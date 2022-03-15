/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linked_list.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/03 12:01:56 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/01/03 12:54:01 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LINKED_LIST_H
# define FT_LINKED_LIST_H

# include <stdbool.h>

/*
**	This was originally the ft_lst...
**	But that confuses me a bit, a list is not a linked list
**	So i changed it.
*/

typedef struct s_linked_list
{
	void					*content;
	struct s_linked_list	*next;
}				t_linked_list;

t_linked_list	*linked_list_new(void *content);
void			linked_list_add_front(t_linked_list **lst, t_linked_list *new);
int				linked_list_size(t_linked_list *lst);
t_linked_list	*linked_list_last(t_linked_list *lst);
void			linked_list_add_back(t_linked_list **lst, t_linked_list *new);
void			linked_list_delone(t_linked_list *lst, void (*del)(void*));
void			linked_list_clear(t_linked_list **lst, void (*del)(void*));
void			linked_list_iter(t_linked_list *lst, void (*f)(void *));
t_linked_list	*linked_list_map(t_linked_list *lst, void *(*f)(void *),
					void (*del)(void *));
bool			linked_list_hascycle(t_linked_list *lst);

#endif
