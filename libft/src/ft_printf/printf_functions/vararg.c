/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vararg.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/30 15:42:32 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/01/10 11:58:43 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

int	ft_vprintf_fd(int fd, const char *format, va_list lst)
{
	t_write_mode_fd_data	data;
	char					buffer[FT_PRINTF_BUFFER_SIZE];

	data.fd = fd;
	data.current = 0;
	data.buffer_size = FT_PRINTF_BUFFER_SIZE;
	data.buffer = buffer;
	return (ft_printf_base(format, lst, &g_write_mode_fd, &data));
}

int	ft_vprintf_str(char *str, size_t size,
	const char *format, va_list lst)
{
	int				ret;
	t_write_sn_data	data;

	data.str = str;
	data.length = size;
	ret = ft_printf_base(format, lst, &g_write_mode_buff, &data);
	return (ret);
}

int	ft_vprintf(const char *format, va_list lst)
{
	t_write_mode_fd_data	data;
	char					buffer[FT_PRINTF_BUFFER_SIZE];

	data.fd = STDOUT_FILENO;
	data.current = 0;
	data.buffer_size = FT_PRINTF_BUFFER_SIZE;
	data.buffer = buffer;
	return (ft_printf_base(format, lst, &g_write_mode_fd, &data));
}
