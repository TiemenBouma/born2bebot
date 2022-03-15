/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_math_min.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 16:24:46 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/03/20 17:26:52 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ternary.h"

char	min_chr(char a, char b)
{
	return (ter_char(a > b, b, a));
}

short	min_short(short a, short b)
{
	return (ter_short(a > b, b, a));
}

int	min_int(int a, int b)
{
	return (ter_int(a > b, b, a));
}

long	min_long(long a, long b)
{
	return (ter_long(a > b, b, a));
}
