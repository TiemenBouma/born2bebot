/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 14:00:11 by jsimonis      #+#    #+#                 */
/*   Updated: 2020/11/03 17:10:51 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*result;

	if (str == NULL)
		return (NULL);
	len = ft_strlen(str) + 1;
	result = (char *)malloc(len * sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, str, len);
	return (result);
}
