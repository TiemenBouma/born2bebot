/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   aabb_contains.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/15 21:42:00 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/02/05 16:19:25 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_aabb.h"

bool	aabb_contains_point(const t_aabb *aabb, const t_vec3 *point)
{
	return (point->x < aabb->max.x && point->x > aabb->min.x
		&& (point->y < aabb->max.y && point->y > aabb->min.y)
		&& (point->z < aabb->max.z && point->z > aabb->min.z));
}

bool	aabb_contains_box(const t_aabb *aabb, const t_aabb *box)
{
	return (box->max.x < aabb->max.x && box->min.x > aabb->min.x
		&& (box->max.y < aabb->max.y && box->min.y > aabb->min.y)
		&& (box->max.z < aabb->max.z && box->min.z > aabb->min.z));
}

bool	aabb_touches_box(const t_aabb *aabb, const t_aabb *box)
{
	return (aabb->max.x > box->min.x && box->max.x > aabb->min.x
		&& (aabb->max.y > box->min.y && box->max.y > aabb->min.y)
		&& (aabb->max.z > box->min.z && box->max.z > aabb->min.z));
}
