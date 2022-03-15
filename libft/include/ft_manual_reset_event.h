/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_manual_reset_event.h                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/21 11:57:10 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/01/31 17:16:17 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MANUAL_RESET_EVENT_H
# define FT_MANUAL_RESET_EVENT_H

# include <pthread.h>
# include <stdbool.h>

typedef struct s_manual_reset_event
{
	pthread_mutex_t	mutex;
	pthread_cond_t	cond;
	bool			is_set;
}				t_manual_reset_event;

int				manual_reset_event_init(t_manual_reset_event *event);
void			manual_reset_event_destroy(t_manual_reset_event *event);
void			manual_reset_event_set(t_manual_reset_event *event);
void			manual_reset_event_reset(t_manual_reset_event *event);
void			manual_reset_event_wait(t_manual_reset_event *event);

#endif
