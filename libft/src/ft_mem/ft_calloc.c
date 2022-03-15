/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 13:43:26 by jsimonis      #+#    #+#                 */
/*   Updated: 2020/10/28 15:32:10 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*pt;

	size = size * count;
	pt = (char *)malloc(size);
	if (pt == NULL)
		return (NULL);
	while (size > 0)
	{
		size--;
		pt[size] = 0;
	}
	return (pt);
}
