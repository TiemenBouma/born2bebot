/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   def_handle_conversions_cspdi.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 18:08:17 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/04/11 13:42:40 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"
#include "ft_ternary.h"

void	def_handle_conversion_c(t_format *format, t_print_state *state)
{
	char	c;

	c = va_arg(state->lst, int);
	write_width((t_strlen){&c, 1}, format, state, 0);
}

/*
**	 Why is that null check needed? WHY? why does the real printf do that?
*/

void	def_handle_conversion_s(t_format *format, t_print_state *state)
{
	char	*str;

	str = va_arg(state->lst, char *);
	if (str == NULL)
		str = "(null)";
	write_width((t_strlen){str, ft_strlen(str)}, format, state, can_trim);
}

void	def_handle_conversion_p(t_format *format, t_print_state *state)
{
	void	*value;
	char	str[16];
	int		len;
	t_base	base;

	value = va_arg(state->lst, void *);
	len = 0;
	base.base = 16;
	base.chars = "0123456789abcdef";
	ft_write_itoa_base((unsigned long)value, &base, str, &len);
	format->hash = true;
	write_width_numeric((t_strlen){str, len},
		(t_strlen){"0x", 2}, format, state);
}

//write_width_numeric((t_strlen){str, len}, (t_strlen){signchar ? &signchar : 
//"", signchar ? 1 : 0}, format, state);

void	def_handle_conversion_d(t_format *format, t_print_state *state)
{
	int		value;
	char	str[11];
	char	signchar;
	int		len;
	t_base	base;

	value = read_with_length(format, state);
	len = 0;
	signchar = get_sign_char(format, value);
	base.base = 10;
	base.chars = "0123456789";
	ft_write_itoa_base(abs_int(value), &base, str, &len);
	if (signchar)
		format->hash = true;
	write_width_numeric((t_strlen){str, len}, (t_strlen){ter_ptr(signchar,
			&signchar, ""), ter_int(signchar, 1, 0)}, format, state);
}

void	def_handle_conversion_i(t_format *format, t_print_state *state)
{
	def_handle_conversion_d(format, state);
}
