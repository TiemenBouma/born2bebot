/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quaternion_math.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jasper <jasper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/22 16:28:33 by jasper        #+#    #+#                 */
/*   Updated: 2021/01/29 17:05:58 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_quaternion.h"
#include <math.h>

/*
**	Wikipedia!
**	Also: http://www.euclideanspace.com/maths/algebra/realNormedAlgebra/
**	quaternions/index.htm
**	Stupid norm, cant even put long links into comments
**	the website says: x = i, y = j, z = k, w = r
*/

void	quaternion_mult(t_quaternion *result,
	const t_quaternion *a, const t_quaternion *b)
{
	*result = (t_quaternion)
	{
		.r = a->r * b->r - a->i * b->i - a->j * b->j - a->k * b->k,
		.i = a->r * b->i + a->i * b->r + a->j * b->k - a->k * b->j,
		.j = a->r * b->j - a->i * b->k + a->j * b->r + a->k * b->i,
		.k = a->r * b->k + a->i * b->j - a->j * b->i + a->k * b->r
	};
}

void	quaternion_conjugate(t_quaternion *result,
	const t_quaternion *a)
{
	*result = (t_quaternion)
	{
		.r = a->r,
		.i = -a->i,
		.j = -a->j,
		.k = -a->k
	};
}

void	quaternion_normalize(t_quaternion *result,
	const t_quaternion *a)
{
	float	magnitude;

	magnitude = sqrtf(a->r * a->r + a->i * a->i + a->j * a->j + a->k * a->k);
	*result = (t_quaternion)
	{
		.r = a->r / magnitude,
		.i = a->i / magnitude,
		.j = a->j / magnitude,
		.k = a->k / magnitude
	};
}

/*
** I wonder if we can simplify more
** It was originally:
**		t_quaternion temp;
**		t_quaternion conjugate;
**
**		quaternion_init(&temp, 0, vec->x, vec->y, vec->z);
**		quaternion_mult(&temp, a, &temp);
**		quaternion_conjugate(&conjugate, a);
**		quaternion_mult(&temp, &temp, &conjugate);
**		vec3_init(result, temp.i, temp.j, temp.k);
*/

void	quaternion_mult_vec3(t_vec3 *result,
	const t_quaternion *a, const t_vec3 *vec)
{
	t_quaternion	con;
	float			ta;
	float			tb;
	float			tc;
	float			te;

	quaternion_conjugate(&con, a);
	ta = con.i * vec->x + con.j * vec->y + con.k * vec->z;
	tb = con.r * vec->x - con.j * vec->z + con.k * vec->y;
	tc = con.r * vec->y + con.i * vec->z - con.k * vec->x;
	te = con.r * vec->z - con.i * vec->y + con.j * vec->x;
	*result = (t_vec3)
	{
		.x = ta * con.i + tb * con.r + tc * con.k - te * con.j,
		.y = ta * con.j - tb * con.k + tc * con.r + te * con.i,
		.z = ta * con.k + tb * con.j - tc * con.i + te * con.r
	};
}
