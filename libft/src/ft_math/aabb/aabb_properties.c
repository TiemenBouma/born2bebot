/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   aabb_properties.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/06 13:19:57 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/03/20 16:48:41 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_aabb.h"

static float	clampf(float value, float min, float max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}

t_vec3	aabb_closest_point(const t_aabb *aabb, const t_vec3 *point)
{
	return ((t_vec3)
		{
			.x = clampf(point->x, aabb->min.x, aabb->max.x),
			.y = clampf(point->x, aabb->min.x, aabb->max.x),
			.z = clampf(point->x, aabb->min.x, aabb->max.x)
		});
}

float	aabb_volume(const t_aabb *aabb)
{
	return ((aabb->max.x - aabb->min.x)
		* (aabb->max.y - aabb->min.y)
		* (aabb->max.z - aabb->min.z));
}
