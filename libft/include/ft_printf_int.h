/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_int.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/30 15:44:30 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/04/05 16:43:50 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INT_H
# define FT_PRINTF_INT_H

# include <unistd.h>
# include <stdio.h>

# include "libft.h"
# include "ft_printf.h"

# ifndef FT_PRINTF_BUFFER_SIZE
#  define FT_PRINTF_BUFFER_SIZE 128
# endif

/*
**	I Should make the default conversion be callable from other conversions...
*/

struct						s_format;
struct						s_print_state;

typedef void				(*t_conversion_func)(struct s_format *format,
	struct s_print_state *state);
typedef void				(*t_write_func)(struct s_print_state *state,
	const char *str, size_t len);
typedef void				(*t_write_complete_func)(struct s_print_state *
	state);

typedef enum e_length
{
	Omitted = 0,
	h = 1,
	hh = 2,
	l = 3,
	ll = 4
}				t_length;

typedef enum e_write_type
{
	numeric = 1 << 0,
	can_trim = 2 << 0,
}				t_write_type;

typedef struct s_format
{
	bool		minus;
	bool		zero;
	bool		hash;
	bool		space;
	bool		plus;
	int			width;
	int			precision;
	t_length	length;
	char		type;
}				t_format;

typedef struct s_write_sn_data
{
	char	*str;
	size_t	length;
}				t_write_sn_data;

typedef struct s_write_mode
{
	t_write_func			write;
	t_write_complete_func	complete;
}				t_write_mode;

typedef struct s_print_state
{
	int				printed;
	va_list			lst;
	void			*write_data;
	t_write_mode	write_mode;
	bool			has_errored;
}				t_print_state;

typedef struct s_write_util_data
{
	bool			minus;
	int				zero_count;
	int				space_count;
	t_print_state	*state;
}				t_write_util_data;

int				ft_printf_base(const char *format, va_list lst,
					const t_write_mode *write_mode, void *write_data);

/*
**	Utility functions
*/

void			read_format(const char *str, int *current,
					t_format *format, t_print_state *state);

void			handle_conversion(t_format *format, t_print_state *state);
void			set_conversion_handle(char type,
					void (*handle)(t_format*, t_print_state*));

void			write_width(t_strlen str, t_format *format,
					t_print_state *state, t_write_type type);
void			write_width_numeric(t_strlen str, t_strlen prefix,
					t_format *format, t_print_state *state);
int				printfrom(const char *str, int last,
					int current, t_print_state *state);
int				printf_atoi(const char *str, int *curr);
char			get_sign_char_u(t_format *format);
char			get_sign_char(t_format *format, int sign);
int				read_with_length(t_format *format, t_print_state *state);
unsigned int	read_with_length_unsigned(t_format *format,
					t_print_state *state);

/*
**	All the default conversion
*/

void			def_handle_conversion_c(t_format *format, t_print_state *state);
void			def_handle_conversion_s(t_format *format, t_print_state *state);
void			def_handle_conversion_p(t_format *format, t_print_state *state);
void			def_handle_conversion_d(t_format *format, t_print_state *state);
void			def_handle_conversion_i(t_format *format, t_print_state *state);
void			def_handle_conversion_u(t_format *format, t_print_state *state);
void			def_handle_conversion_x(t_format *format, t_print_state *state);
void			def_handle_conversion_ux(t_format *format,
					t_print_state *state);
void			def_handle_conversion_precent(t_format *format,
					t_print_state *state);
void			def_handle_conversion_n(t_format *format, t_print_state *state);
void			def_handle_conversion_f(t_format *format, t_print_state *state);
void			def_handle_conversion_g(t_format *format, t_print_state *state);
void			def_handle_conversion_e(t_format *format, t_print_state *state);

/*
**	All the default write modes
*/

typedef struct s_write_mode_fd_data
{
	int		fd;
	char	*buffer;
	size_t	current;
	size_t	buffer_size;
}				t_write_mode_fd_data;

void			ft_printf_write_fd(t_print_state *state,
					const char *str, size_t len);
void			ft_printf_write_fd_complete(t_print_state *state);
void			ft_printf_write_buff(t_print_state *state,
					const char *str, size_t len);
void			ft_printf_write_buff_complete(t_print_state *state);

static const t_write_mode	g_write_mode_fd = (t_write_mode){
	ft_printf_write_fd, ft_printf_write_fd_complete
};
static const t_write_mode	g_write_mode_buff = (t_write_mode){
	ft_printf_write_buff, ft_printf_write_buff_complete
};

#endif
