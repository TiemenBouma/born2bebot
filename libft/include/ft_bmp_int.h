/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bmp_int.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/24 16:14:26 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/02/24 16:40:38 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BMP_INT_H
# define FT_BMP_INT_H

typedef struct s_bmp_header
{
	int	file_size;
	int	data_offset;
}				t_bmp_header;

typedef struct s_info_header
{
	int	width;
	int	height;
	int	bits_per_pixel;
	int	compression;
	int	image_size;
	int	x_pixels_per_m;
	int	y_pixels_per_m;
	int	num_colors_used;
	int	important_colors;
}				t_bmp_info_header;

#endif