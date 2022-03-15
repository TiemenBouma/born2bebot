/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   def_handle_conversions_fge.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/02 11:18:19 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/01/16 14:21:44 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

/*
** always as normal
*/

void	def_handle_conversion_f(t_format *format, t_print_state *state)
{
	double	v;

	v = va_arg(state->lst, double);
	(void)format;
	(void)v;
}

/*
** normal if small number, exponent if big number
*/

void	def_handle_conversion_g(t_format *format, t_print_state *state)
{
	double	v;

	v = va_arg(state->lst, double);
	(void)format;
	(void)v;
}

/*
** always as exponent
*/

void	def_handle_conversion_e(t_format *format, t_print_state *state)
{
	double	v;

	v = va_arg(state->lst, double);
	(void)format;
	(void)v;
}
