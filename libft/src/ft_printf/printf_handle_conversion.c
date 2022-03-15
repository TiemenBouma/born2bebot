/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_handle_conversion.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/06 17:55:42 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/04/11 22:01:09 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"
//#include <stdlib.h>

static void	init_default_conversions(void)
{
	set_conversion_handle('c', def_handle_conversion_c);
	set_conversion_handle('s', def_handle_conversion_s);
	set_conversion_handle('p', def_handle_conversion_p);
	set_conversion_handle('d', def_handle_conversion_d);
	set_conversion_handle('i', def_handle_conversion_i);
	set_conversion_handle('u', def_handle_conversion_u);
	set_conversion_handle('x', def_handle_conversion_x);
	set_conversion_handle('X', def_handle_conversion_ux);
	set_conversion_handle('%', def_handle_conversion_precent);
	set_conversion_handle('n', def_handle_conversion_n);
	set_conversion_handle('f', def_handle_conversion_f);
	set_conversion_handle('g', def_handle_conversion_g);
	set_conversion_handle('e', def_handle_conversion_e);
}

static t_conversion_func	*get_conversion_pt(char type)
{
	static t_conversion_func	arr[256];
	static bool					init = false;

	if (init == false)
	{
		init = true;
		ft_bzero(arr, 256 * sizeof(t_conversion_func));
		init_default_conversions();
	}
	return (&arr[(unsigned char)type]);
}

void	set_conversion_handle(char type,
	void (*f)(t_format*, t_print_state*))
{
	*get_conversion_pt(type) = f;
}

void	handle_conversion(t_format *format,
	t_print_state *state)
{
	t_conversion_func	*handle;

	handle = get_conversion_pt(format->type);
	if (handle != NULL)
		(*handle)(format, state);
}
