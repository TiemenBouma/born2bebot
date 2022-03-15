/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 14:09:27 by jsimonis      #+#    #+#                 */
/*   Updated: 2020/10/31 15:43:08 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	while (len > 0)
	{
		len--;
		*((char *)dst) = *((char *)src);
		if ((unsigned char)c == *((unsigned char *)src))
			return (dst + 1);
		dst++;
		src++;
	}
	return (NULL);
}
