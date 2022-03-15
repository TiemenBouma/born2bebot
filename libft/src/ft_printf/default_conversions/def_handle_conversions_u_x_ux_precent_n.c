/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   def_handle_conversions_u_x_ux_precent_n.c          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 14:11:28 by jsimonis      #+#    #+#                 */
/*   Updated: 2020/12/30 15:47:02 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

void	def_handle_conversion_u(t_format *format, t_print_state *state)
{
	unsigned int	value;
	char			str[10];
	int				len;
	t_base			base;

	value = read_with_length_unsigned(format, state);
	len = 0;
	base.base = 10;
	base.chars = "0123456789";
	ft_write_itoa_base(value, &base, str, &len);
	write_width_numeric((t_strlen){str, len}, (t_strlen){"", 0}, format, state);
}

/*
** Once again, WHY do i need the if (value == 0) hash = false? WHY printf? WHY!?
*/

void	def_handle_conversion_x(t_format *format, t_print_state *state)
{
	unsigned int	value;
	char			str[8];
	int				len;
	t_base			base;

	value = read_with_length_unsigned(format, state);
	len = 0;
	base.base = 16;
	base.chars = "0123456789abcdef";
	ft_write_itoa_base(value, &base, str, &len);
	if (value == 0)
		format->hash = false;
	write_width_numeric((t_strlen){str, len},
		(t_strlen){"0x", 2}, format, state);
}

void	def_handle_conversion_ux(t_format *format, t_print_state *state)
{
	unsigned int	value;
	char			str[8];
	int				len;
	t_base			base;

	value = read_with_length_unsigned(format, state);
	len = 0;
	base.base = 16;
	base.chars = "0123456789ABCDEF";
	ft_write_itoa_base(value, &base, str, &len);
	if (value == 0)
		format->hash = false;
	write_width_numeric((t_strlen){str, len},
		(t_strlen){"0X", 2}, format, state);
}

void	def_handle_conversion_precent(t_format *format, t_print_state *state)
{
	write_width((t_strlen){"%", 1}, format, state, 0);
}

/*
**	Thease type of generic functions are awesome,
**	just put em in where ever you want extra customizability.
**	But now it complains about unused parameters! grrr!
**	Void it!
*/

void	def_handle_conversion_n(t_format *format, t_print_state *state)
{
	*va_arg(state->lst, int *) = state->printed;
	(void)(format);
}

/*
**	I have absolutely no clue how to read floating point or fixed point notation
*/

/*
**void	def_handle_conversion_f(t_format *format, t_print_state *state)
**{
**
**}
**
**void	def_handle_conversion_g(t_format *format, t_print_state *state)
**{
**
**}
**
**void	def_handle_conversion_e(t_format *format, t_print_state *state)
**{
**
**}
*/
