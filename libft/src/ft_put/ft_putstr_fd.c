/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 17:21:09 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/06/27 10:07:29 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*
**	return the write works, since ~0 == -1
*/

int	ft_putstr_fd(const char *s, int fd)
{
	if (s == NULL)
		return (write(fd, "{NULL}", 6));
	else
		return (write(fd, s, ft_strlen(s)));
}
