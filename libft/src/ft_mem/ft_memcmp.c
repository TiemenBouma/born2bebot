/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 15:06:28 by jsimonis      #+#    #+#                 */
/*   Updated: 2020/10/27 16:44:08 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(void *s1, void *s2, size_t n)
{
	size_t	curr;

	curr = 0;
	while (curr < n)
	{
		if (((unsigned char *)s1)[curr] != ((unsigned char *)s2)[curr])
		{
			return (((unsigned char *)s1)[curr] - ((unsigned char *)s2)[curr]);
		}
		curr++;
	}
	return (0);
}
