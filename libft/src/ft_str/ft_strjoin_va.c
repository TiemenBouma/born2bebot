/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin_va.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 12:49:54 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/01/31 16:28:49 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdarg.h>

/*
**	Same as strjoin, but with any number of strings
*/

char	*ft_strjoin_va(int num_strings, ...)
{
	va_list	lst;
	char	*ptr;
	char	*tmp;
	int		i;

	va_start(lst, num_strings);
	ptr = NULL;
	i = 0;
	while (i < num_strings)
	{
		tmp = ptr;
		ptr = ft_strjoin(ptr, va_arg(lst, char *));
		if (tmp)
			free(tmp);
		if (!ptr)
		{
			va_end(lst);
			return (NULL);
		}
		i++;
	}
	va_end(lst);
	return (ptr);
}
