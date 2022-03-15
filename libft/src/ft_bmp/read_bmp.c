/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_bmp.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/24 16:08:13 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/03/20 16:09:30 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include "ft_bmp_int.h"

static bool	read_value(int fd, int *value, int len)
{
	__uint8_t	tmp;
	int			count;

	*value = 0;
	count = 0;
	while (len > 0)
	{
		if (read(fd, &tmp, 1) == -1)
			return (false);
		*value |= tmp << (count * 8);
		len--;
		count++;
	}
	return (true);
}

static bool	read_bmp_header(int fd, t_bmp_header *header)
{
	char	BM[2];
	int		reserved;

	if (read(fd, BM, 2) == -1
		|| !read_value(fd, &header->file_size, 4)
		|| !read_value(fd, &reserved, 4)
		|| !read_value(fd, &header->data_offset, 4)
		|| BM[0] != 'B' || BM[1] != 'M')
		return (false);
	return (true);
}

static bool	read_bmp_info_header(int fd, t_bmp_info_header *info_header)
{
	int	size;
	int	planes;

	if (!read_value(fd, &size, 4)
		|| !read_value(fd, &info_header->width, 4)
		|| !read_value(fd, &info_header->height, 4)
		|| !read_value(fd, &planes, 2)
		|| !read_value(fd, &info_header->bits_per_pixel, 2)
		|| !read_value(fd, &info_header->compression, 4)
		|| !read_value(fd, &info_header->image_size, 4)
		|| !read_value(fd, &info_header->x_pixels_per_m, 4)
		|| !read_value(fd, &info_header->y_pixels_per_m, 4)
		|| !read_value(fd, &info_header->num_colors_used, 4)
		|| !read_value(fd, &info_header->important_colors, 4)
		|| size != 40
		|| planes != 1)
		return (false);
	return (true);
}

static bool	read_bmp_pixels_uncompressed(int fd, unsigned char *pixels,
	t_bmp_info_header *info_header)
{
	unsigned char	*pixel;
	int				x;
	int				y;
	static char		padding[3];

	y = 0;
	while (y < info_header->height)
	{
		x = 0;
		while (x < info_header->width)
		{
			pixel = pixels + (x * 3)
				+ (info_header->height - y - 1) * info_header->width * 3;
			if (read(fd, pixel + 2, 1) == -1
				|| read(fd, pixel + 1, 1) == -1
				|| read(fd, pixel, 1) == -1)
				return (false);
			x++;
		}
		if (read(fd, padding, ((info_header->width * 3 + 3) / 4 * 4)
				- info_header->width * 3) == -1)
			return (false);
		y++;
	}
	return (true);
}

/*
**	Too lazy to make it able to read compressed images
**	so just return false if it is compressed
*/

unsigned char	*read_bmp(int fd, int *width, int *height)
{
	t_bmp_header		header;
	t_bmp_info_header	info_header;
	unsigned char		*pixels;

	if (!read_bmp_header(fd, &header)
		|| !read_bmp_info_header(fd, &info_header))
		return (NULL);
	if (info_header.bits_per_pixel != 24
		|| info_header.compression != 0
		|| info_header.image_size != 0)
		return (false);
	pixels = malloc(info_header.width * info_header.height * 3);
	if (!pixels || !read_bmp_pixels_uncompressed(fd, pixels, &info_header))
	{
		free(pixels);
		return (NULL);
	}
	*width = info_header.width;
	*height = info_header.height;
	return (pixels);
}
