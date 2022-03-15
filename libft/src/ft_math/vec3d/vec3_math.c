/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec3_math.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/16 14:17:21 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/01/26 16:27:09 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vec3.h"

void	vec3_add(t_vec3 *result, const t_vec3 *a, const t_vec3 *b)
{
	*result = (t_vec3){
		.x = a->x + b->x,
		.y = a->y + b->y,
		.z = a->z + b->z
	};
}

void	vec3_subtract(t_vec3 *result, const t_vec3 *a, const t_vec3 *b)
{
	*result = (t_vec3){
		.x = a->x - b->x,
		.y = a->y - b->y,
		.z = a->z - b->z
	};
}

void	vec3_multiply(t_vec3 *result, const t_vec3 *a, const t_vec3 *b)
{
	*result = (t_vec3){
		.x = a->x * b->x,
		.y = a->y * b->y,
		.z = a->z * b->z
	};
}

void	vec3_divide(t_vec3 *result, const t_vec3 *a, const t_vec3 *b)
{
	*result = (t_vec3){
		.x = a->x / b->x,
		.y = a->y / b->y,
		.z = a->z / b->z
	};
}

void	vec3_scale(t_vec3 *result, const t_vec3 *a, float scale)
{
	*result = (t_vec3){
		.x = a->x * scale,
		.y = a->y * scale,
		.z = a->z * scale
	};
}
