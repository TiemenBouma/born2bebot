/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_init.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 12:18:07 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/03/20 16:30:05 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_init.h"
#include "ft_error.h"

/*
**	Commonly used by some of the create_init functions when they fail to init
*/

bool	init_fail(t_init_data *init_data)
{
	(void)init_data;
	return (false);
}

int	init_values(int num_values, t_init_data *data)
{
	int	i;

	i = 0;
	while (i < num_values)
	{
		if (!data[i].init_func(&data[i]))
		{
			set_error(data[i].error_msg, false);
			free_values(i, data);
			return (~i);
		}
		i++;
	}
	return (0);
}

void	free_values(int num_values, t_init_data *data)
{
	int	i;

	i = 0;
	while (i < num_values)
	{
		data[i].free_func(&data[i]);
		i++;
	}
}

t_init_data	init_data_create(t_init_func init_func,
	t_free_func free_func, void *data, char *error_msg)
{
	return ((t_init_data)
		{
			.init_func = init_func,
			.free_func = free_func,
			.data = data,
			.error_msg = error_msg
		});
}
