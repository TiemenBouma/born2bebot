/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_quaternion.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/15 21:27:24 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/01/16 14:20:30 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QUATERNION_H
# define FT_QUATERNION_H

# include "ft_vec3.h"
# include "ft_matrix.h"

typedef struct s_quaternion
{
	float	r;
	float	i;
	float	j;
	float	k;
}					t_quaternion;

const t_quaternion	*quaternion_identity(void);
void				quaternion_from_axis_angle(t_quaternion *result,
						const t_vec3 *axis, float angle);
void				quaternion_mult(t_quaternion *result,
						const t_quaternion *a, const t_quaternion *b);
void				quaternion_conjugate(t_quaternion *result,
						const t_quaternion *a);
void				quaternion_normalize(t_quaternion *result,
						const t_quaternion *a);
void				quaternion_mult_vec3(t_vec3 *result, const t_quaternion *a,
						const t_vec3 *vec);
void				quaternion_from_matrix(t_quaternion *result,
						const t_matrix3x3 *matrix);
void				quaternion_from_forward_up(t_quaternion *result,
						const t_vec3 *forward, const t_vec3 *up);

#endif
