/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 16:06:51 by jsimonis      #+#    #+#                 */
/*   Updated: 2020/12/30 11:25:22 by jasper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	ft_is_needle(const char *str, const char *needle)
{
	while (true)
	{
		if (*needle == '\0')
			return (true);
		if (*str != *needle)
			return (false);
		needle++;
		str++;
	}
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	curr;
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *)haystack);
	curr = 0;
	while (haystack[curr] != '\0' && curr + needle_len <= len)
	{
		if (ft_is_needle(haystack + curr, needle))
			return ((char *)(haystack + curr));
		curr++;
	}
	return (NULL);
}
