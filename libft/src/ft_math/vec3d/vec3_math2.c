/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec3_math2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jasper <jasper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/22 16:25:49 by jasper        #+#    #+#                 */
/*   Updated: 2021/01/31 17:16:31 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vec3.h"
#include <math.h>

float	vec3_magnitude_sqr(const t_vec3 *a)
{
	return (a->x * a->x + a->y * a->y + a->z * a->z);
}

float	vec3_magnitude(const t_vec3 *a)
{
	return (sqrtf(vec3_magnitude_sqr(a)));
}

void	vec3_normalize(t_vec3 *result, const t_vec3 *a)
{
	vec3_scale(result, a, 1 / vec3_magnitude(a));
}

float	vec3_dot(const t_vec3 *a, const t_vec3 *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}
