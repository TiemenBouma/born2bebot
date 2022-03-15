/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 15:02:43 by jsimonis      #+#    #+#                 */
/*   Updated: 2020/10/31 16:01:00 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	curr;

	curr = 0;
	while (curr < n)
	{
		if (((unsigned char *)s)[curr] == (unsigned char)c)
			return ((void *)s + curr);
		curr++;
	}
	return (NULL);
}
