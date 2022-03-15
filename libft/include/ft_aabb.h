/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_aabb.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/15 21:33:04 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/02/06 13:21:24 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_AABB_H
# define FT_AABB_H

# include "ft_vec3.h"
# include "ft_quaternion.h"
# include <stdbool.h>

typedef struct s_aabb
{
	t_vec3	min;
	t_vec3	max;
}				t_aabb;

void			aabb_init(t_aabb *result, const t_vec3 *point);
void			aabb_extend_point(t_aabb *aabb, const t_vec3 *point);
void			aabb_extend_box(t_aabb *aabb, const t_aabb *box);
void			aabb_rotate(t_aabb *aabb, const t_quaternion *quat);

bool			aabb_contains_point(const t_aabb *aabb, const t_vec3 *point);
bool			aabb_contains_box(const t_aabb *aabb, const t_aabb *box);
bool			aabb_touches_box(const t_aabb *aabb, const t_aabb *box);

float			aabb_volume(const t_aabb *aabb);
t_vec3			aabb_closest_point(const t_aabb *aabb, const t_vec3 *point);

#endif
