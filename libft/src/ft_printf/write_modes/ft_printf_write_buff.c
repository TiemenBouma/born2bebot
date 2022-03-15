/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_write_buff.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/10 11:28:31 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/01/10 11:43:56 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

void	ft_printf_write_buff(t_print_state *state, const char *str, size_t len)
{
	t_write_sn_data	*data;
	size_t			current;
	size_t			end;

	data = state->write_data;
	current = state->printed;
	end = current + len;
	if (end > data->length)
	{
		len = data->length - current;
		ft_memcpy(data->str + current, str, len);
		state->has_errored = true;
	}
	else
		ft_memcpy(data->str + current, str, len);
	state->printed += len;
}

void	ft_printf_write_buff_complete(t_print_state *state)
{
	(void)state;
}
