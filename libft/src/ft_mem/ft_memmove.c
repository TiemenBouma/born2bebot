/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 15:34:44 by jsimonis      #+#    #+#                 */
/*   Updated: 2020/11/03 16:44:33 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	curr;

	if (dst == src)
		return (dst);
	if (dst > src)
	{
		curr = len;
		while (curr > 0)
		{
			curr--;
			((char *)dst)[curr] = ((char *)src)[curr];
		}
	}
	else
	{
		curr = 0;
		while (curr < len)
		{
			((char *)dst)[curr] = ((char *)src)[curr];
			curr++;
		}
	}
	return (dst);
}
