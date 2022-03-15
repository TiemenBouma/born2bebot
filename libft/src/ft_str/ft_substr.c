/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 12:07:03 by jsimonis      #+#    #+#                 */
/*   Updated: 2020/11/03 17:11:16 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	size_t	end;
	char	*pt;

	if (str == NULL)
		return (ft_strdup(""));
	end = 0;
	while (end < start + len && str[end])
		end++;
	if (end < start)
		end = start;
	pt = (char *)malloc(end - start + 1);
	if (pt == NULL)
		return (pt);
	pt[end - start] = '\0';
	while (end > start)
	{
		end--;
		pt[end - start] = str[end];
	}
	return (pt);
}
