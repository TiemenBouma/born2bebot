/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_time.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/18 13:06:41 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/01/21 12:10:24 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TIME_H
# define FT_TIME_H

typedef struct s_timeval
{
	long	seconds;
	long	micro_seconds;
}				t_time;

t_time			time_now(void);
float			time_difference(t_time *a, t_time *b);

#endif
