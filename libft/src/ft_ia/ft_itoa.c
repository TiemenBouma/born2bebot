/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 13:36:16 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/04/11 22:01:57 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include "libft.h"
#include "ft_ternary.h"

static int	ft_get_char_count(long n)
{
	int		count;

	count = 1;
	n /= 10;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	ft_write_itoa(char *pt, long num, int offset)
{
	pt[offset] = '0' + (num % 10);
	if (num >= 10)
		ft_write_itoa(pt, num / 10, offset - 1);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*pt;

	len = ter_int(n < 0, 1, 0) + ft_get_char_count(ter_long(n < 0, -(long)n, n))
		;
	pt = malloc(len + 1);
	if (pt == NULL)
		return (pt);
	pt[len] = '\0';
	if (n < 0)
		pt[0] = '-';
	ft_write_itoa(pt, ter_long(n < 0, -(long)n, n), len - 1);
	return (pt);
}
