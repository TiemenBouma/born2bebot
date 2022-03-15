/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 17:23:22 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/03/20 17:03:48 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_write_itoa(long num, int fd)
{
	int	written;

	if (num >= 10)
	{
		written = ft_write_itoa(num / 10, fd);
		if (written < 0)
			return (written);
	}
	else
		written = 0;
	if (write(fd, &"0123456789" [num % 10], 1) == -1)
		return (~written);
	return (written + 1);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	out;

	if (n < 0)
	{
		if (write(fd, "-", 1) == -1)
			return (~0);
		out = ft_write_itoa(-(long)n, fd);
		if (out < 0)
			return (~(~out + 1));
		return (out + 1);
	}
	else
		return (ft_write_itoa(n, fd));
}
