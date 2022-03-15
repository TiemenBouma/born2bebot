/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bmp.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/24 16:09:25 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/02/24 17:05:00 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BMP_H
# define FT_BMP_H

# include <stdbool.h>

bool			write_bmp(int fd, unsigned char *pixels, int width, int height);
unsigned char	*read_bmp(int fd, int *width, int *height);

#endif