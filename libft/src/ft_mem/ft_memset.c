/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 13:12:08 by jsimonis      #+#    #+#                 */
/*   Updated: 2020/10/28 18:12:15 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *pt, int value, size_t len)
{
	while (len > 0)
	{
		len--;
		((unsigned char *)pt)[len] = (unsigned char)value;
	}
	return (pt);
}
