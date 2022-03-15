/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_shared_ptr.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/28 19:04:26 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/02/05 13:48:30 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHARED_PTR_H
# define FT_SHARED_PTR_H

# include <stdbool.h>

typedef void		(*t_free_func)(void *ptr);

typedef struct s_shared_pt
{
	void			*ptr;
	unsigned int	count;
	t_free_func		free_ptr;
}				t_shared_pt;

void			shared_pt_init(t_shared_pt *ptr, void *data,
					t_free_func free_ptr);
void			shared_pt_un_init(t_shared_pt *ptr);
t_shared_pt		*shared_pt_new(void *data, t_free_func free_ptr);
void			shared_pt_free(t_shared_pt *ptr);

void			shared_pt_get(t_shared_pt *ptr);
bool			shared_pt_release(t_shared_pt *ptr);

/*
**	same as shared_pt_release, but also frees the shared pointer itself
*/

bool			shared_pt_release_and_free(t_shared_pt *ptr);

#endif
