/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/06 13:05:36 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/03/20 16:18:22 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "ft_ternary.h"

int	ft_get_char_count_base(unsigned long n, t_base *base)
{
	int		count;

	count = 1;
	n /= base->base;
	while (n > 0)
	{
		n /= base->base;
		count++;
	}
	return (count);
}

void	ft_write_itoa_base(unsigned long num, t_base *base, char *str, int *len)
{
	if (num >= base->base)
		ft_write_itoa_base(num / base->base, base, str, len);
	str[*len] = base->chars[num % base->base];
	(*len)++;
}

char	*ft_itoa_base(int n, t_base *base)
{
	int		len;
	char	*pt;

	len = ter_int(n < 0, 1, 0) + ft_get_char_count_base(abs_int(n), base);
	pt = malloc(len + 1);
	if (pt == NULL)
		return (pt);
	pt[len] = '\0';
	if (n < 0)
		pt[0] = '-';
	len = ter_int(n < 0, 1, 0);
	ft_write_itoa_base(abs_int(n), base, pt, &len);
	return (pt);
}
