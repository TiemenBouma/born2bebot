/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_math_abs.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/06 13:13:58 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/04/11 22:01:53 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//#include <limits.h>
#include "ft_ternary.h"

unsigned char	abs_chr(char c)
{
	if (c == (char) - 128)
		return (128);
	return (ter_uchar(c > 0, c, -c));
}

unsigned short	abs_short(short c)
{
	if (c == (short) - 32768)
		return (32768);
	return (ter_ushort(c > 0, c, -c));
}

unsigned int	abs_int(int c)
{
	if (c == (int) - 2147483648)
		return (2147483648);
	return (ter_uint(c > 0, c, -c));
}

unsigned long	abs_long(long c)
{
	if (c == (long) - 9223372036854775808UL)
		return (9223372036854775808UL);
	return (ter_ulong(c > 0, c, -c));
}
