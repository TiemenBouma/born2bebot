/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_init_manual_reset_event.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 12:55:11 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/02/11 11:34:21 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_init_create_threading.h"

static bool	init_manual_reset_event(t_init_data *init_data)
{
	return (manual_reset_event_init(init_data->data) == 0);
}

static void	free_manual_reset_event(t_init_data *init_data)
{
	manual_reset_event_destroy(init_data->data);
}

t_init_data	init_data_create_mre(t_manual_reset_event *mre, char *error_msg)
{
	return (init_data_create(init_manual_reset_event,
			free_manual_reset_event, mre, error_msg));
}
