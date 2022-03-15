/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_unicode_length.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 11:49:58 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/04/11 22:01:30 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//#include <stdbool.h>

/*
** decodes what type of UFT-8 unicode char [c] is
**		0 = ascii
**		1 = continuation
**		2 or more = start unicode char
**			return = number of chars this unicode uses
*/

int	ft_unicode_length(char c)
{
	unsigned char	chr;

	chr = c;
	if (chr & 128)
	{
		if (chr & 64)
		{
			if (chr & 32)
			{
				if (chr & 16)
				{
					return (4);
				}
				return (3);
			}
			return (2);
		}
		return (1);
	}
	return (0);
}
