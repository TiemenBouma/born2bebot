/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 12:55:39 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/04/11 22:01:35 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdlib.h>

/*
**	Someone complained about using the "bonus" ft_strcontains
**		inside mandatory parts
**	So i replaced it with strchr, less readable imo
*/

char	*ft_strtrim(const char *str, const char *set)
{
	size_t	start;
	size_t	end;

	if (str == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(str));
	start = 0;
	end = ft_strlen(str);
	while (ft_strchr(set, str[start]) && start < end)
		start++;
	while (ft_strchr(set, str[end - 1]) && end - 1 > start)
		end--;
	return (ft_substr(str, start, end - start));
}
