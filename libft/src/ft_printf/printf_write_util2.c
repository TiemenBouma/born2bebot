/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_write_util2.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 14:37:31 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/01/10 11:36:23 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

int	printfrom(const char *str, int last,
	int current, t_print_state *state)
{
	state->write_mode.write(state, str + last, current - last);
	return (current - last);
}
