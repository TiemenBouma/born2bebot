/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   aabb.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/15 21:33:57 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/01/26 16:23:56 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_aabb.h"

void	aabb_init(t_aabb *result, const t_vec3 *point)
{
	*result = (t_aabb)
	{
		.max = *point,
		.min = *point
	};
}

void	aabb_extend_point(t_aabb *aabb, const t_vec3 *point)
{
	if (point->x > aabb->max.x)
		aabb->max.x = point->x;
	else if (point->x < aabb->min.x)
		aabb->min.x = point->x;
	if (point->y > aabb->max.y)
		aabb->max.y = point->y;
	else if (point->y < aabb->min.y)
		aabb->min.y = point->y;
	if (point->z > aabb->max.z)
		aabb->max.z = point->z;
	else if (point->z < aabb->min.z)
		aabb->min.z = point->z;
}

void	aabb_extend_box(t_aabb *aabb, const t_aabb *box)
{
	if (box->max.x > aabb->max.x)
		aabb->max.x = box->max.x;
	if (box->min.x < aabb->min.x)
		aabb->min.x = box->min.x;
	if (box->max.y > aabb->max.y)
		aabb->max.y = box->max.y;
	if (box->min.y < aabb->min.y)
		aabb->min.y = box->min.y;
	if (box->max.z > aabb->max.z)
		aabb->max.z = box->max.z;
	if (box->min.z < aabb->min.z)
		aabb->min.z = box->min.z;
}

/*
**	Sets the AABB to the rotated AABB
**	max defines the extends, center is assumed to be at 0,0,0
**	does invert the y coordinate of max, but whatever
**	by negating the rotated point we get a cheap second point
*/

static void	aabb_rotate_ext(t_aabb *aabb, t_vec3 *max, const t_quaternion *quat)
{
	t_vec3	temp;

	quaternion_mult_vec3(&temp, quat, max);
	aabb_init(aabb, &temp);
	vec3_negate(&temp, &temp);
	aabb_extend_point(aabb, &temp);
	max->z = -max->z;
	quaternion_mult_vec3(&temp, quat, max);
	aabb_extend_point(aabb, &temp);
	vec3_negate(&temp, &temp);
	aabb_extend_point(aabb, &temp);
	max->y = -max->y;
	quaternion_mult_vec3(&temp, quat, max);
	aabb_extend_point(aabb, &temp);
	vec3_negate(&temp, &temp);
	aabb_extend_point(aabb, &temp);
	max->z = -max->z;
	quaternion_mult_vec3(&temp, quat, max);
	aabb_extend_point(aabb, &temp);
	vec3_negate(&temp, &temp);
	aabb_extend_point(aabb, &temp);
}

/*
**	Calculates a different representation of the bounding box
**	rotates it with center at 0,0,0
**	and then moves it back to the correct center
*/

void	aabb_rotate(t_aabb *aabb, const t_quaternion *quat)
{
	t_vec3	max;
	t_vec3	center;

	vec3_subtract(&max, &aabb->max, &aabb->min);
	vec3_scale(&max, &max, 0.5);
	vec3_add(&center, &aabb->min, &max);
	aabb_rotate_ext(aabb, &max, quat);
	vec3_add(&aabb->max, &aabb->max, &center);
	vec3_add(&aabb->min, &aabb->min, &center);
}
