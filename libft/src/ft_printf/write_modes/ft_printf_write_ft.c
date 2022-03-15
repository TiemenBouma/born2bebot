/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_write_ft.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/10 11:28:22 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/01/10 12:02:35 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

void	ft_printf_write_fd(t_print_state *state, const char *str, size_t len)
{
	int						result;
	t_write_mode_fd_data	*data;
	size_t					unused_buffer;

	data = state->write_data;
	unused_buffer = data->buffer_size - data->current;
	if (len > unused_buffer)
	{
		ft_memcpy(data->buffer + data->current, str, unused_buffer);
		state->printed += unused_buffer;
		result = write(*(int *)state->write_data, data->buffer,
				data->buffer_size);
		if (result < 0)
			state->has_errored = true;
		data->current = 0;
		ft_printf_write_fd(state, str + unused_buffer, len - unused_buffer);
	}
	else
	{
		ft_memcpy(data->buffer + data->current, str, len);
		state->printed += len;
		data->current += len;
	}
}

void	ft_printf_write_fd_complete(t_print_state *state)
{
	int						result;
	t_write_mode_fd_data	*data;

	data = state->write_data;
	result = write(*(int *)state->write_data, data->buffer, data->current);
	if (result < 0)
		state->has_errored = true;
}
