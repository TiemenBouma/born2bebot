/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_write_util.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 16:24:15 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/01/10 11:32:54 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

static void	write_char(char c, int count, t_print_state *state)
{
	while (count >= 1)
	{
		state->write_mode.write(state, &c, 1);
		count -= 1;
	}
}

static int	get_zero_len(t_format *format)
{
	if (format->precision >= 0)
		return (format->precision);
	if (format->zero && !format->minus)
		return (format->width);
	return (0);
}

/*
**	Ughh, whyyyyy norm
*/

static void	write_width_numeric_util(t_strlen *str, t_strlen *prefix,
	t_write_util_data *data)
{
	if (data->minus)
	{
		data->state->write_mode.write(data->state, prefix->str, prefix->len);
		write_char('0', data->zero_count, data->state);
		data->state->write_mode.write(data->state, str->str, str->len);
		write_char(' ', data->space_count, data->state);
	}
	else
	{
		write_char(' ', data->space_count, data->state);
		data->state->write_mode.write(data->state, prefix->str, prefix->len);
		write_char('0', data->zero_count, data->state);
		data->state->write_mode.write(data->state, str->str, str->len);
	}
}

/*
**	Step 1:
**	Handle precision, trim if nessesairy, add zeros
**	Step 2: handle width
*/

void	write_width_numeric(t_strlen str, t_strlen prefix,
	t_format *format, t_print_state *state)
{
	int					space_count;
	int					zero_count;
	t_write_util_data	data;

	if (!format->hash)
		prefix.len = 0;
	if (format->precision == 0 && str.len == 1 && str.str[0] == '0')
		str.len = 0;
	space_count = max_int(format->width - str.len - prefix.len, 0);
	if (format->precision >= 0)
		zero_count = max_int(get_zero_len(format) - str.len, 0);
	else
		zero_count = max_int(get_zero_len(format) - str.len - prefix.len, 0);
	space_count = max_int(space_count - zero_count, 0);
	data = (t_write_util_data){format->minus, zero_count, space_count, state};
	write_width_numeric_util(&str, &prefix, &data);
}

void	write_width(t_strlen str, t_format *format,
	t_print_state *state, t_write_type type)
{
	int	space_count;

	if (type & can_trim && format->precision >= 0)
		str.len = min_int(str.len, format->precision);
	space_count = max_int(format->width - str.len, 0);
	if (format->minus)
	{
		state->write_mode.write(state, str.str, str.len);
		write_char(' ', space_count, state);
	}
	else
	{
		if (format->zero)
			write_char('0', space_count, state);
		else
			write_char(' ', space_count, state);
		state->write_mode.write(state, str.str, str.len);
	}
}
