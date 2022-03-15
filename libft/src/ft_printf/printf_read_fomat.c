/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_read_fomat.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/06 18:01:53 by jsimonis      #+#    #+#                 */
/*   Updated: 2020/12/30 15:47:19 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

static void	read_flags(const char *str, int *current, t_format *format)
{
	format->minus = false;
	format->zero = false;
	format->hash = false;
	format->space = false;
	format->plus = false;
	while (ft_strcontains("-0# +", str[*current]))
	{
		if (str[*current] == '-')
			format->minus = true;
		else if (str[*current] == '0')
			format->zero = true;
		else if (str[*current] == '#')
			format->hash = true;
		else if (str[*current] == ' ')
			format->space = true;
		else if (str[*current] == '+')
			format->plus = true;
		(*current)++;
	}
}

static void	read_width(const char *str, int *current, t_format *format,
	t_print_state *state)
{
	format->width = -1;
	if (str[*current] == '*')
	{
		format->width = va_arg(state->lst, int);
		if (format->width < 0)
		{
			format->minus = true;
			format->width = -(format->width);
		}
		(*current)++;
	}
	else
	{
		format->width = printf_atoi(str, current);
	}
}

static void	read_precision(const char *str, int *current, t_format *format,
	t_print_state *state)
{
	format->precision = -1;
	if (str[*current] == '.')
	{
		(*current)++;
		if (str[*current] == '*')
		{
			format->precision = va_arg(state->lst, int);
			(*current)++;
		}
		else
		{
			format->precision = printf_atoi(str, current);
		}
	}
}

static void	read_length(const char *str, int *current, t_format *format)
{
	format->length = Omitted;
	if (str[*current] == 'h')
	{
		(*current)++;
		if (str[*current] == 'h')
		{
			(*current)++;
			format->length = hh;
		}
		else
			format->length = h;
	}
	else if (str[*current] == 'l')
	{
		(*current)++;
		if (str[*current] == 'l')
		{
			(*current)++;
			format->length = ll;
		}
		else
			format->length = l;
	}
}

void	read_format(const char *str, int *current, t_format *format,
	t_print_state *state)
{
	read_flags(str, current, format);
	read_width(str, current, format, state);
	read_precision(str, current, format, state);
	read_length(str, current, format);
	format->type = str[*current];
	(*current)++;
}
