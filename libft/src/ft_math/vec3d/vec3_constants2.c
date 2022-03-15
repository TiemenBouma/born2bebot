/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec3_constants2.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/16 14:15:42 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/03/22 13:54:38 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vec3.h"

const t_vec3	*vec3_left(void)
{
	static const t_vec3	vec = {
		.x = -1,
		.y = 0,
		.z = 0
	};

	return (&vec);
}

const t_vec3	*vec3_down(void)
{
	static const t_vec3	vec = {
		.x = 0,
		.y = -1,
		.z = 0
	};

	return (&vec);
}

const t_vec3	*vec3_forward(void)
{
	static const t_vec3	vec = {
		.x = 0,
		.y = 0,
		.z = -1
	};

	return (&vec);
}

const t_vec3	*vec3_one(void)
{
	static const t_vec3	vec = {
		.x = 1,
		.y = 1,
		.z = 1
	};

	return (&vec);
}
