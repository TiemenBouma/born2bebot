/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 16:03:47 by jsimonis      #+#    #+#                 */
/*   Updated: 2020/10/31 15:49:26 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	curr;

	curr = 0;
	while (curr < n)
	{
		if (s1[curr] != s2[curr])
		{
			return (((unsigned char *)s1)[curr] - ((unsigned char *)s2)[curr]);
		}
		if (s1[curr] == '\0')
			return (0);
		curr++;
	}
	return (0);
}
