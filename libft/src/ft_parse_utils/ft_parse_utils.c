/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_parse_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/26 16:58:07 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/08/08 15:08:56 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse_utils.h"
#include "ft_error.h"
#include "libft.h"
#include "ft_ternary.h"
#include <limits.h>

// If you are complaining about the ter_int, well...
// i can replace it with this beautiful piece of code:
//	((~0) >> 1) + is_negative

// u * 10 + v > y (contains u*10, overflow can happen)
// u > (y - v)/10 (does not overflow)

static bool	read_is_negative(const char *str, int *current)
{
	if (skip_char(str, current, '-'))
		return (true);
	skip_char(str, current, '+');
	return (false);
}

bool	read_int(const char *str, int *current, int *value)
{
	int				start;
	bool			is_negative;
	unsigned int	unsigned_value;
	unsigned int	max_value;

	start = *current;
	unsigned_value = 0;
	is_negative = read_is_negative(str, current);
	max_value = ter_uint(is_negative, (unsigned int)INT_MAX + 1, INT_MAX);
	while (ft_isdigit(str[*current]))
	{
		if (unsigned_value > (max_value - (unsigned int)(str[*current] - '0')) /
			10)
		{
			set_error("Value out of range!", false);
			*value = ter_int(is_negative, INT_MIN, INT_MAX);
			skip_digits(str, current);
			return (false);
		}
		unsigned_value = unsigned_value * 10 + str[*current] - '0';
		(*current)++;
	}
	*value = ter_int(is_negative, -unsigned_value, unsigned_value);
	return (start != *current);
}

bool	read_llong(const char *str, int *current, long long *value)
{
	int					start;
	bool				is_negative;
	unsigned long long	unsigned_value;
	unsigned long long	max_value;

	start = *current;
	unsigned_value = 0;
	is_negative = read_is_negative(str, current);
	max_value = ter_ullong(is_negative, (unsigned long long)LLONG_MAX + 1,
			LLONG_MAX);
	while (ft_isdigit(str[*current]))
	{
		if (unsigned_value > (max_value - (unsigned long long)(str[*current]
				 - '0')) / 10)
		{
			set_error("Value out of range!", false);
			*value = ter_llong(is_negative, LLONG_MIN, LLONG_MAX);
			skip_digits(str, current);
			return (false);
		}
		unsigned_value = unsigned_value * 10 + str[*current] - '0';
		(*current)++;
	}
	*value = ter_llong(is_negative, -unsigned_value, unsigned_value);
	return (start != *current);
}
