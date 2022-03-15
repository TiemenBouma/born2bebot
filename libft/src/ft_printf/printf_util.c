/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_util.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/06 18:16:07 by jsimonis      #+#    #+#                 */
/*   Updated: 2020/12/30 15:47:19 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

char	get_sign_char_u(t_format *format)
{
	if (format->plus)
		return ('+');
	else if (format->space)
		return (' ');
	else
		return (0);
}

char	get_sign_char(t_format *format, int sign)
{
	if (sign >= 0)
		return (get_sign_char_u(format));
	else
		return ('-');
}

int	read_with_length(t_format *format, t_print_state *state)
{
	int	value;

	value = va_arg(state->lst, int);
	if (format->length == h)
		return ((short)value);
	if (format->length == hh)
		return ((char)value);
	return (value);
}

unsigned int	read_with_length_unsigned(t_format *format,
	t_print_state *state)
{
	unsigned int	value;

	value = va_arg(state->lst, unsigned int);
	if (format->length == h)
		return ((unsigned short)value);
	if (format->length == hh)
		return ((unsigned char)value);
	return (value);
}

int	printf_atoi(const char *str, int *curr)
{
	int	sum;

	sum = 0;
	while (str[*curr] >= '0' && str[*curr] <= '9')
	{
		sum = sum * 10 + (str[*curr] - '0');
		(*curr)++;
	}
	return (sum);
}
