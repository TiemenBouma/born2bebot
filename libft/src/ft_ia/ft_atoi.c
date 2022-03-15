/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 16:24:44 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/04/11 22:02:01 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include "ft_ternary.h"

/*
**	Someone complained about using the "bonus" ft_isspace inside mandatory parts
**	so i just inlined it, cant even complain about bogus functions either!
*/

int	ft_atoi(char *str)
{
	long	sum;
	int		sign;

	while (*str == ' ' || *str == '\f' || *str == '\n'
		|| *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	sign = ter_int(*str == '-', -1, 1);
	if (*str == '-' || *str == '+')
		str++;
	sum = 0;
	while (*str >= '0' && *str <= '9')
	{
		sum = sum * 10 + (*str - '0');
		str++;
	}
	return ((int)(sum * sign));
}
