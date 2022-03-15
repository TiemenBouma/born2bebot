/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_math_max.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 16:24:46 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/03/20 16:56:31 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ternary.h"

char	max_chr(char a, char b)
{
	return (ter_char(a > b, a, b));
}

short	max_short(short a, short b)
{
	return (ter_short(a > b, a, b));
}

int	max_int(int a, int b)
{
	return (ter_int(a > b, a, b));
}

long	max_long(long a, long b)
{
	return (ter_long(a > b, a, b));
}
