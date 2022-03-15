/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 16:36:13 by jsimonis      #+#    #+#                 */
/*   Updated: 2020/10/31 15:49:10 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	curr;

	curr = 0;
	while (curr + 1 < dstsize && src[curr])
	{
		dst[curr] = src[curr];
		curr++;
	}
	if (dstsize > 0)
		dst[curr] = '\0';
	while (src[curr])
		curr++;
	return (curr);
}
