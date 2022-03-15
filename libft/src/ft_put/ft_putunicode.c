/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putunicode_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 18:45:45 by jsimonis      #+#    #+#                 */
/*   Updated: 2020/12/30 16:26:24 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_putu_chars_fd(unsigned int u_chars, int fd)
{
	int	out;

	out = 0;
	while (u_chars > 0)
	{
		if (write(fd, &u_chars, 1) <= 0)
			return (~out);
		u_chars = u_chars >> 8;
		out++;
	}
	return (out);
}

int	ft_putu_point_fd(unsigned int u_point, int fd)
{
	int	len;

	return (ft_putu_chars_fd(ft_unicode_tochars(u_point, &len), fd));
}
