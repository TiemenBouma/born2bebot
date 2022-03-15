/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 13:10:52 by jsimonis      #+#    #+#                 */
/*   Updated: 2020/11/10 13:33:49 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memdup(const void *src, size_t len)
{
	char	*pt;

	if (src == NULL)
		return (NULL);
	pt = malloc(len);
	if (pt != NULL)
		ft_memcpy(pt, src, len);
	return (pt);
}
