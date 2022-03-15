/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 16:40:44 by jsimonis      #+#    #+#                 */
/*   Updated: 2020/12/30 11:25:13 by jasper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	curr;
	size_t	from;

	curr = 0;
	while (dst[curr] && curr < dstsize)
		curr++;
	from = 0;
	while (src[from] && curr + 1 < dstsize)
	{
		dst[curr] = src[from];
		from++;
		curr++;
	}
	if (from > 0)
		dst[curr] = '\0';
	while (src[from])
	{
		from++;
		curr++;
	}
	return (curr);
}
