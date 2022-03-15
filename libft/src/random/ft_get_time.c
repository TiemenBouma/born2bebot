/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_get_time.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/18 13:03:30 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/01/31 16:28:34 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stddef.h>
#include "ft_time.h"

/*
**	using gettimeofday is probably fine, i mean, i can use sqrtf and such
**	I probably wont be needing it for non-bonus related stuff
*/

t_time	time_now(void)
{
	struct timeval	current;
	t_time			mapped;

	gettimeofday(&current, NULL);
	mapped.seconds = current.tv_sec;
	mapped.micro_seconds = current.tv_usec;
	return (mapped);
}

float	time_difference(t_time *a, t_time *b)
{
	return ((a->seconds - b->seconds)
		+ 0.000001 * (a->micro_seconds - b->micro_seconds));
}
