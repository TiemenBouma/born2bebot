/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_bmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jasper <jasper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 15:39:55 by jasper        #+#    #+#                 */
/*   Updated: 2021/02/24 16:08:32 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

/*
** Super basic BMP file writer, no fancy compression or non 24 bit colors
** BMP files are stored in little endian
*/

static bool	write_value(int fd, int value, int len)
{
	__uint8_t	tmp;

	while (len > 0)
	{
		tmp = (__uint8_t)(value & 0xFF);
		if (write(fd, &tmp, 1) == -1)
			return (false);
		value = value >> 8;
		len--;
	}
	return (true);
}

/*
**	multi-line if statements for the win!
*/

static bool	write_bmp_header(int fd, int width, int height)
{
	if (write(fd, "BM", 2) == -1
		|| !write_value(fd, 14 + 40 + ((width * 3 + 3) / 4 * 4) * height, 4)
		|| !write_value(fd, 0, 4)
		|| !write_value(fd, 14 + 40, 4))
		return (false);
	return (true);
}

static bool	write_info_header(int fd, int width, int height)
{
	if (!write_value(fd, 40, 4)
		|| !write_value(fd, width, 4)
		|| !write_value(fd, height, 4)
		|| !write_value(fd, 1, 2)
		|| !write_value(fd, 24, 2)
		|| !write_value(fd, 0, 4)
		|| !write_value(fd, 0, 4)
		|| !write_value(fd, 1024, 4)
		|| !write_value(fd, 1024, 4)
		|| !write_value(fd, 0, 4)
		|| !write_value(fd, 0, 4))
		return (false);
	return (true);
}

static bool	write_pixels(int fd, unsigned char *pixels, int width, int height)
{
	int				x;
	int				y;
	unsigned char	*pixel;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			pixel = pixels + (x * 3) + (height - y - 1) * width * 3;
			if (write(fd, pixel + 2, 1) == -1
				|| write(fd, pixel + 1, 1) == -1
				|| write(fd, pixel, 1) == -1)
				return (false);
			x++;
		}
		if (write(fd, "\0\0\0", ((width * 3 + 3) / 4 * 4) - width * 3) == -1)
			return (false);
		y++;
	}
	return (true);
}

/*
**	Pixels are left to right, top to bottom
**	Pixels are in RGB format
*/

bool	write_bmp(int fd, unsigned char *pixels, int width, int height)
{
	if (!write_bmp_header(fd, width, height)
		|| !write_info_header(fd, width, height)
		|| !write_pixels(fd, pixels, width, height))
		return (false);
	return (true);
}
