/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcontains.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 12:56:14 by jsimonis      #+#    #+#                 */
/*   Updated: 2020/11/10 13:54:48 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	ft_strcontains(const char *str, char chr)
{
	int	curr;

	if (!str)
		return (false);
	curr = 0;
	while (str[curr])
	{
		if (str[curr] == chr)
			return (true);
		curr++;
	}
	return (false);
}
