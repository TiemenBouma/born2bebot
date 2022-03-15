/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putarr_fd_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 13:31:05 by jsimonis      #+#    #+#                 */
/*   Updated: 2020/12/30 16:16:59 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putarr_fd(const void *arr, int len, int fd)
{
	int	i;
	int	curr;

	if (arr == NULL)
		return (~0);
	i = 0;
	while (i < len)
	{
		curr = ft_putnbr_fd(((unsigned char *)arr)[i], fd);
		if (curr <= 0)
			return (~i);
		i += curr;
		if (ft_putchar_fd(' ', fd) < 0)
			return (~i);
		i++;
	}
	return (i);
}
