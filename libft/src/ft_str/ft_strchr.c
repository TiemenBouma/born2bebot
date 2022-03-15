/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 16:33:07 by jsimonis      #+#    #+#                 */
/*   Updated: 2020/10/26 16:33:56 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

char	*ft_strchr(char *s, int c)
{
	while (true)
	{
		if (*s == (char)c)
			return (s);
		if (*s == '\0')
			return (NULL);
		s++;
	}
}
