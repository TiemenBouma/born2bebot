/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 14:04:24 by jsimonis      #+#    #+#                 */
/*   Updated: 2020/10/27 16:41:56 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *pt, size_t len)
{
	while (len > 0)
	{
		len--;
		((char *)pt)[len] = 0;
	}
}
