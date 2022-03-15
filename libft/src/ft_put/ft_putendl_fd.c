/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 17:22:15 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/06/27 10:07:25 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_putendl_fd(const char *s, int fd)
{
	int	out;

	out = ft_putstr_fd(s, fd);
	if (out < 0)
		return (out);
	if (write(fd, "\n", 1) == -1)
		return (~out);
	return (out + 1);
}
