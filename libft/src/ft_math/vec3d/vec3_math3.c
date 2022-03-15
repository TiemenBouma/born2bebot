/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec3_math3.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jasper <jasper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/22 16:25:49 by jasper        #+#    #+#                 */
/*   Updated: 2021/01/26 16:27:18 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vec3.h"

void	vec3_cross(t_vec3 *result, const t_vec3 *a, const t_vec3 *b)
{
	*result = (t_vec3){
		.x = a->y * b->z - a->z * b->y,
		.y = a->z * b->x - a->x * b->z,
		.z = a->x * b->y - a->y * b->x
	};
}

void	vec3_negate(t_vec3 *result, const t_vec3 *a)
{
	*result = (t_vec3){
		.x = -a->x,
		.y = -a->y,
		.z = -a->z
	};
}
