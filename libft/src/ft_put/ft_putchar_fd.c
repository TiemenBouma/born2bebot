/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 17:45:44 by jsimonis      #+#    #+#                 */
/*   Updated: 2020/12/30 16:17:40 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar_fd(char c, int fd)
{
	if (write(fd, &c, 1) == -1)
		return (~0);
	return (1);
}
