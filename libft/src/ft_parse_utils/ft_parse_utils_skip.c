/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_parse_utils_skip.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/26 16:58:25 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/08/08 14:26:19 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//#include <stdbool.h>
#include "libft.h"

// When we read a overflowing number, its nice to read all the digits

void	skip_digits(const char *str, int *current)
{
	while (ft_isdigit(str[*current]))
		(*current)++;
}

bool	skip_char(const char *str, int *current, char chr)
{
	if (str[*current] == chr)
	{
		(*current)++;
		return (true);
	}
	return (false);
}

void	skip_whitespace(const char *str, int *current)
{
	while (ft_isspace(str[*current]))
		(*current)++;
}
