/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec3_constants.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/16 14:15:42 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/03/20 16:49:31 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vec3.h"

/*
**	Ugh, norminette+ complains when i do: t_vec3 vec = { .x=1, .y=0, .z=0 };
**	Complains about multiple operations
**	And normal norminette complains when i split it over multiple lines
**	Saying that declerations must be followed by a empty line
**	But this, this is just dumb, and so much worse that it should be
**	but hey, explicit variable naming!
*/

const t_vec3	*vec3_right(void)
{
	static const t_vec3	vec = {
		.x = 1,
		.y = 0,
		.z = 0
	};

	return (&vec);
}

const t_vec3	*vec3_up(void)
{
	static const t_vec3	vec = {
		.x = 0,
		.y = 1,
		.z = 0
	};

	return (&vec);
}

const t_vec3	*vec3_back(void)
{
	static const t_vec3	vec = {
		.x = 0,
		.y = 0,
		.z = 1
	};

	return (&vec);
}
