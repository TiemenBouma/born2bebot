/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_rand.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jasper <jasper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/25 16:25:40 by jasper        #+#    #+#                 */
/*   Updated: 2021/05/17 14:11:21 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vec3.h"
#include <math.h>

//#define M_PI 3.14159265358979323846264338327950288

/*
** Welp, guess i can just copy the values from the real rand() function
** Easy!
*/

int	ft_rand(void)
{
	static long	result = 1;

	result = result * 214013L + 2531011L;
	return ((result >> 16) & 0x7fff);
}

/*
**	Returns a random number between 0 and 1
*/

float	ft_randf(void)
{
	return (ft_rand() / (float)0x7fff);
}

t_vec3	random_on_sphere(void)
{
	float	theta;
	float	phi;

	theta = ft_randf() * 2 * M_PI;
	phi = acosf(1 - 2 * ft_randf());
	return ((t_vec3)
		{
			.x = sin(phi) * cos(theta),
			.y = cos(phi),
			.z = sin(phi) * sin(theta),
		});
}

t_vec3	random_in_hemisphere(const t_vec3 *normal)
{
	t_vec3	dir;
	float	dot;
	t_vec3	temp;

	dir = random_on_sphere();
	dot = vec3_dot(&dir, normal);
	if (dot < 0)
	{
		vec3_scale(&temp, normal, dot * -2);
		vec3_add(&dir, &dir, &temp);
	}
	return (dir);
}
