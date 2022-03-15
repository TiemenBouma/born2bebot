/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vec3.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/15 21:25:55 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/03/22 13:54:18 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VEC3_H
# define FT_VEC3_H

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}					t_vec3;

const t_vec3		*vec3_left(void);
const t_vec3		*vec3_right(void);
const t_vec3		*vec3_up(void);
const t_vec3		*vec3_down(void);
const t_vec3		*vec3_forward(void);
const t_vec3		*vec3_back(void);
const t_vec3		*vec3_one(void);

void				vec3_clone(t_vec3 *result, const t_vec3 *vec);
void				vec3_add(t_vec3 *result, const t_vec3 *a, const t_vec3 *b);
void				vec3_subtract(t_vec3 *result, const t_vec3 *a,
						const t_vec3 *b);
void				vec3_multiply(t_vec3 *result, const t_vec3 *a,
						const t_vec3 *b);
void				vec3_divide(t_vec3 *result, const t_vec3 *a,
						const t_vec3 *b);
void				vec3_scale(t_vec3 *result, const t_vec3 *a, float scale);
float				vec3_magnitude_sqr(const t_vec3 *a);
float				vec3_magnitude(const t_vec3 *a);
void				vec3_normalize(t_vec3 *result, const t_vec3 *a);
float				vec3_dot(const t_vec3 *a, const t_vec3 *b);
void				vec3_cross(t_vec3 *result, const t_vec3 *a,
						const t_vec3 *b);
void				vec3_negate(t_vec3 *result, const t_vec3 *a);

#endif
