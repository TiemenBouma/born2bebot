/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   basic.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/30 15:42:32 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/01/10 11:57:34 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

int	ft_printf_fd(int fd, const char *format, ...)
{
	int						ret;
	va_list					lst;
	t_write_mode_fd_data	data;
	char					buffer[FT_PRINTF_BUFFER_SIZE];

	va_start(lst, format);
	data.fd = fd;
	data.current = 0;
	data.buffer_size = FT_PRINTF_BUFFER_SIZE;
	data.buffer = buffer;
	ret = ft_printf_base(format, lst, &g_write_mode_fd, &data);
	va_end(lst);
	return (ret);
}

int	ft_printf_str(char *str, size_t size, const char *format, ...)
{
	int				ret;
	va_list			lst;
	t_write_sn_data	data;

	va_start(lst, format);
	data.str = str;
	data.length = size;
	ret = ft_printf_base(format, lst, &g_write_mode_buff, &data);
	va_end(lst);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	int						ret;
	va_list					lst;
	t_write_mode_fd_data	data;
	char					buffer[FT_PRINTF_BUFFER_SIZE];

	va_start(lst, format);
	data.fd = STDOUT_FILENO;
	data.current = 0;
	data.buffer_size = FT_PRINTF_BUFFER_SIZE;
	data.buffer = buffer;
	ret = ft_printf_base(format, lst, &g_write_mode_fd, &data);
	va_end(lst);
	return (ret);
}
