/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/05 11:23:55 by jsimonis      #+#    #+#                 */
/*   Updated: 2020/12/30 16:24:35 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>

int			ft_printf(const char *format, ...);
int			ft_printf_fd(int fd, const char *format, ...);
int			ft_printf_str(char *str, size_t size, const char *format, ...);

int			ft_vprintf(const char *format, va_list lst);
int			ft_vprintf_fd(int fd, const char *format, va_list lst);
int			ft_vprintf_str(char *str, size_t size,
				const char *format, va_list lst);

#endif
