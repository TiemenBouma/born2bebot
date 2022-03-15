/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_init_create_threading.h                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 12:16:27 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/02/11 11:39:41 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INIT_CREATE_THREADING_H
# define FT_INIT_CREATE_THREADING_H

# include "ft_init.h"
# include "ft_manual_reset_event.h"

typedef struct s_init_data_mutex_attr
{
	pthread_mutex_t				*mutex;
	const pthread_mutexattr_t	*attr;
}				t_init_data_mutex_attr;

t_init_data		init_data_create_mutex_attr(pthread_mutex_t *mutex,
					const pthread_mutexattr_t *attr, char *error_msg);
t_init_data		init_data_create_mutex(pthread_mutex_t *mutex, char *error_msg);
t_init_data		init_data_create_mre(t_manual_reset_event *mre,
					char *error_msg);

#endif
