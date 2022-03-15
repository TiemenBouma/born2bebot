/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 17:06:30 by jsimonis      #+#    #+#                 */
/*   Updated: 2020/11/03 17:11:04 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*pt;

	if (s == NULL)
		return (NULL);
	if (f == NULL)
		return (ft_strdup(s));
	len = ft_strlen(s);
	pt = malloc((len + 1) * sizeof(char));
	if (pt == NULL)
		return (NULL);
	pt[len] = '\0';
	while (len > 0)
	{
		len--;
		pt[len] = (*f)((unsigned int)len, s[len]);
	}
	return (pt);
}
