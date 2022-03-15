/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quaternion_constants.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jasper <jasper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/22 16:28:33 by jasper        #+#    #+#                 */
/*   Updated: 2021/04/11 22:01:48 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_quaternion.h"
//#include <math.h>

const t_quaternion	*quaternion_identity(void)
{
	static const t_quaternion	quat = {
		.r = 1,
		.i = 0,
		.j = 0,
		.k = 0
	};

	return (&quat);
}
