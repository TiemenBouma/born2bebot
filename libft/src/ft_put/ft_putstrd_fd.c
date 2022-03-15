/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstrd_fd_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 13:34:59 by jsimonis      #+#    #+#                 */
/*   Updated: 2020/12/30 16:16:52 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstrd_fd(const char *str, int fd)
{
	int	i;

	if (str == NULL)
		return (~0);
	i = 0;
	while (str[i])
	{
		if (ft_putchard_fd(str[i], fd) < 0)
			return (~i);
		i++;
	}
	return (i);
}
