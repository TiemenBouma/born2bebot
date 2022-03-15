/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quaternion_from.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/16 14:09:13 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/01/29 17:05:56 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_quaternion.h"
#include <math.h>

void	quaternion_from_axis_angle(t_quaternion *result,
	const t_vec3 *axis, const float angle)
{
	float	s;
	float	c;

	s = sinf(angle / 2);
	c = cosf(angle / 2);
	*result = (t_quaternion)
	{
		.r = c,
		.i = axis->x * s,
		.j = axis->y * s,
		.k = axis->z * s
	};
}

/*
**	This function looked nice before the norm
**	But then the 25 lines rule said no, so now i have this abomination
*/

static void	quaternion_from_matrix_part_2(t_quaternion *result,
	const t_matrix3x3 *matrix)
{
	float	s;

	if (matrix->yy > matrix->zz)
	{
		s = sqrtf(1 + matrix->yy - matrix->xx - matrix->zz) * 2;
		*result = (t_quaternion)
		{
			.r = (matrix->zx - matrix->xz) / s,
			.i = (matrix->yx + matrix->xy) / s,
			.j = 0.25 * s,
			.k = (matrix->zy + matrix->yz) / s
		};
	}
	else
	{
		s = sqrtf(1 + matrix->zz - matrix->xx - matrix->yy) * 2;
		*result = (t_quaternion)
		{
			.r = (matrix->xy - matrix->yx) / s,
			.i = (matrix->zx + matrix->xz) / s,
			.j = (matrix->zy + matrix->yz) / s,
			.k = 0.25 * s
		};
	}
}

void	quaternion_from_matrix(t_quaternion *result,
	const t_matrix3x3 *matrix)
{
	float	tr;
	float	s;

	tr = matrix->xx + matrix->yy + matrix->zz;
	if (tr > 0)
	{
		s = sqrt(tr + 1) * 2;
		*result = (t_quaternion){
			.r = 0.25 * s,
			.i = (matrix->yz - matrix->zy) / s,
			.j = (matrix->zx - matrix->xz) / s,
			.k = (matrix->xy - matrix->yx) / s
		};
	}
	else if ((matrix->xx > matrix->yy) && (matrix->xx > matrix->zz))
	{
		s = sqrtf(1 + matrix->xx - matrix->yy - matrix->zz) * 2;
		*result = (t_quaternion){
			.r = (matrix->yz - matrix->zy) / s,
			.i = 0.25 * s,
			.j = (matrix->yx + matrix->xy) / s,
			.k = (matrix->zx + matrix->xz) / s};
	}
	else
		quaternion_from_matrix_part_2(result, matrix);
}

/*
**	From the 2 vectors calculate the side axis
**	Now we have 3 vectors all at 90 degrees, AKA: a matrix
**	Now we can call quaternion_from_matrix to create a quaternion from it
*/

void	quaternion_from_forward_up(t_quaternion *result,
	const t_vec3 *forward, const t_vec3 *up)
{
	t_vec3		side;
	t_vec3		a_up;
	t_matrix3x3	matrix;

	vec3_cross(&side, forward, up);
	vec3_normalize(&side, &side);
	vec3_cross(&a_up, &side, forward);
	matrix.xx = side.x;
	matrix.xy = side.y;
	matrix.xz = side.z;
	matrix.yx = a_up.x;
	matrix.yy = a_up.y;
	matrix.yz = a_up.z;
	matrix.zx = -forward->x;
	matrix.zy = -forward->y;
	matrix.zz = -forward->z;
	quaternion_from_matrix(result, &matrix);
}
