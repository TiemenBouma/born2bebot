/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchard_fd_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 13:49:56 by jsimonis      #+#    #+#                 */
/*   Updated: 2020/12/30 16:26:18 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchard_fd(char c, int fd)
{
	int	out;

	if ((!ft_isprint(c) || (ft_isspace(c) && c != ' ')))
	{
		if (ft_putchar_fd('\\', fd))
			return (0);
		if (c == '\f')
			out = ft_putchar_fd('f', fd);
		else if (c == '\n')
			out = ft_putchar_fd('n', fd);
		else if (c == '\r')
			out = ft_putchar_fd('r', fd);
		else if (c == '\t')
			out = ft_putchar_fd('t', fd);
		else if (c == '\v')
			out = ft_putchar_fd('v', fd);
		else
			out = ft_putnbr_fd((unsigned char)c, fd);
		if (out < 0)
			return (~(~out + 1));
		return (out + 1);
	}
	else
		return (ft_putchar_fd(c, fd));
}
