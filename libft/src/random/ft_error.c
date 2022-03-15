/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_error.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jasper <jasper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/23 11:25:25 by jasper        #+#    #+#                 */
/*   Updated: 2021/04/11 22:01:44 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

static bool	*get_should_free(void)
{
	static bool	should_free = false;

	return (&should_free);
}

static char	**get_error_location(void)
{
	static char	*error_msg = NULL;

	return (&error_msg);
}

char	*get_last_error(void)
{
	return (*get_error_location());
}

void	set_error(char *error_msg, bool should_free)
{
	if (*get_should_free())
		free(*get_error_location());
	if (error_msg == NULL)
		return (set_error("malloc failed!", false));
	*get_error_location() = error_msg;
	*get_should_free() = should_free;
}

void	clear_error(void)
{
	if (*get_should_free())
		free(*get_error_location());
	*get_error_location() = NULL;
	*get_should_free() = false;
}
