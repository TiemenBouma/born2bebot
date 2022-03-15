/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_shared_ptr_access.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/28 19:04:14 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/04/11 22:01:14 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shared_ptr.h"
#include <unistd.h>
#include <stdlib.h>
//#include "libft.h"

/*
**	write_but_no_warning, the most beautiful function ever created
*/

static int	write_but_no_warning(int fd, char *buf, size_t count)
{
	return (write(fd, buf, count));
}

void	shared_pt_get(t_shared_pt *ptr)
{
	if (ptr->count == 0)
	{
		write_but_no_warning(STDOUT_FILENO,
			"tried to get a shared ptr that was already unused!\n", 51);
		exit(1);
	}
	if (ptr->count == 2147483647)
	{
		write_but_no_warning(STDERR_FILENO,
			"shared_pt overflowed!\n", 23);
		exit(1);
	}
	ptr->count++;
}

/*
**	Returns true when this was the last pointer to this pointer
*/

bool	shared_pt_release(t_shared_pt *ptr)
{
	if (ptr->count == 0)
	{
		write_but_no_warning(STDERR_FILENO,
			"tried to release a shared ptr that was already unused!\n", 55);
		exit(1);
	}
	ptr->count--;
	if (ptr->count == 0)
	{
		ptr->free_ptr(ptr->ptr);
		return (true);
	}
	return (false);
}

/*
**	Returns true when this was the last pointer to this pointer
*/

bool	shared_pt_release_and_free(t_shared_pt *ptr)
{
	bool	last_hold;

	last_hold = shared_pt_release(ptr);
	if (last_hold)
		free(ptr);
	return (last_hold);
}
