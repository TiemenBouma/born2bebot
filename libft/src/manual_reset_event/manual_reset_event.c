/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   manual_reset_event.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/21 11:56:58 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/01/31 16:27:12 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_manual_reset_event.h"

int	manual_reset_event_init(t_manual_reset_event *event)
{
	int	ret;

	ret = pthread_mutex_init(&event->mutex, NULL);
	if (ret != 0)
		return (ret);
	ret = pthread_cond_init(&event->cond, NULL);
	if (ret != 0)
	{
		pthread_mutex_destroy(&event->mutex);
		return (ret);
	}
	event->is_set = false;
	return (ret);
}

void	manual_reset_event_destroy(t_manual_reset_event *event)
{
	pthread_mutex_destroy(&event->mutex);
	pthread_cond_destroy(&event->cond);
}

void	manual_reset_event_set(t_manual_reset_event *event)
{
	pthread_mutex_lock(&event->mutex);
	event->is_set = true;
	pthread_cond_broadcast(&event->cond);
	pthread_mutex_unlock(&event->mutex);
}

void	manual_reset_event_reset(t_manual_reset_event *event)
{
	pthread_mutex_lock(&event->mutex);
	event->is_set = false;
	pthread_mutex_unlock(&event->mutex);
}

void	manual_reset_event_wait(t_manual_reset_event *event)
{
	pthread_mutex_lock(&event->mutex);
	if (!event->is_set)
		pthread_cond_wait(&event->cond, &event->mutex);
	pthread_mutex_unlock(&event->mutex);
}
