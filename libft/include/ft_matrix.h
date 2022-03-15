/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_matrix.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/15 21:28:30 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/01/16 14:19:00 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATRIX_H
# define FT_MATRIX_H

typedef struct s_matrix3x3
{
	float	xx;
	float	yx;
	float	zx;

	float	xy;
	float	yy;
	float	zy;

	float	xz;
	float	yz;
	float	zz;
}					t_matrix3x3;

#endif
