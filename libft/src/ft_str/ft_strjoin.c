/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 12:49:54 by jsimonis      #+#    #+#                 */
/*   Updated: 2020/11/03 17:10:55 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	prefixlen;
	size_t	suffixlen;
	char	*pt;

	if (s1 == NULL && s2 == NULL)
		return (ft_strdup(""));
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	prefixlen = ft_strlen(s1);
	suffixlen = ft_strlen(s2);
	pt = (char *)malloc(prefixlen + suffixlen + 1);
	if (pt == NULL)
		return (NULL);
	ft_memcpy(pt, s1, prefixlen);
	ft_memcpy(pt + prefixlen, s2, suffixlen);
	pt[prefixlen + suffixlen] = '\0';
	return (pt);
}
