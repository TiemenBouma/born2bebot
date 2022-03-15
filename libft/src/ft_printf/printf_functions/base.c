/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   base.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 17:23:10 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/01/10 11:43:50 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

/*
**	too manny lines grrr
*/

static void	init_state(t_print_state *state, const t_write_mode *write_mode,
	void *write_data)
{
	state->printed = 0;
	state->write_mode = *write_mode;
	state->write_data = write_data;
	state->has_errored = false;
}

/*
**	(*current)++; to skip the %
*/

static void	do_conversion(const char *format,
	t_print_state *state, int *current)
{
	t_format	format_data;

	(*current)++;
	read_format(format, current, &format_data, state);
	handle_conversion(&format_data, state);
}

int	ft_printf_base(const char *format, va_list lst,
	const t_write_mode *write_mode, void *write_data)
{
	int				current;
	int				last;
	t_print_state	state;

	init_state(&state, write_mode, write_data);
	current = 0;
	last = 0;
	va_copy(state.lst, lst);
	while (format[current])
	{
		if (format[current] == '%')
		{
			state.printed += printfrom(format, last, current, &state);
			do_conversion(format, &state, &current);
			last = current;
		}
		else
			current++;
	}
	state.printed += printfrom(format, last, current, &state);
	va_end(state.lst);
	state.write_mode.complete(&state);
	if (state.has_errored)
		return (~state.printed);
	return (state.printed);
}
