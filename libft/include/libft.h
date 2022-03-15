/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 12:59:45 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/06/27 10:07:51 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdbool.h>
# include <stddef.h>

// Dislike doing that here, oh wells
# include "ft_vec3.h"

typedef struct s_base
{
	const char		*chars;
	unsigned int	base;
}				t_base;

typedef struct s_strlen
{
	char		*str;
	size_t		len;
}				t_strlen;

int				ft_atoi(char *str);
char			*ft_itoa(int n);

int				ft_get_char_count_base(unsigned long n, t_base *base);
void			ft_write_itoa_base(unsigned long num, t_base *base,
					char *str, int *len);
char			*ft_itoa_base(int n, t_base *base);

void			*ft_calloc(size_t count, size_t size);

bool			ft_isalnum(int c);
bool			ft_isalpha(int c);
bool			ft_isascii(int c);
bool			ft_isdigit(int c);
bool			ft_isprint(int c);
bool			ft_isspace(char c);
bool			ft_ispar(char c);

int				ft_unicode_length(char c);
unsigned int	ft_unicode_tochars(unsigned int u_point, int *len);
unsigned int	ft_unicode_tochars_1(unsigned int u_point);
unsigned int	ft_unicode_tochars_2(unsigned int u_point);
unsigned int	ft_unicode_tochars_3(unsigned int u_point);
unsigned int	ft_unicode_tochars_4(unsigned int u_point);

void			ft_bzero(void *pt, size_t len);
int				ft_memcmp(void *s1, void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t len);
void			*ft_memccpy(void *dst, const void *src, int c, size_t len);
void			*ft_memset(void *pt, int value, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memdup(const void *src, size_t len);

int				ft_toupper(int c);
int				ft_tolower(int c);

char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char			*ft_strdup(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlen(const char *str);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_substr(const char *str, unsigned int start, size_t len);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strjoin_va(int num_strings, ...);
char			*ft_strtrim(const char *s1, const char *set);
bool			ft_strcontains(const char *str, char chr);
char			**ft_split(const char *s, char c);
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));

/*
**	All ft_put functions return the number of characters written
**	if it fails it will return
**		the ones complement of the number of characters already written
*/

int				ft_putchar_fd(char c, int fd);
int				ft_putchard_fd(char c, int fd);
int				ft_putstr_fd(const char *s, int fd);
int				ft_putstrd_fd(const char *str, int fd);
int				ft_putendl_fd(const char *s, int fd);
int				ft_putnbr_fd(int n, int fd);
int				ft_putarr_fd(const void *arr, int len, int fd);
int				ft_putu_point_fd(unsigned int u_point, int fd);
int				ft_putu_chars_fd(unsigned int u_chars, int fd);

unsigned char	abs_chr(char c);
unsigned short	abs_short(short c);
unsigned int	abs_int(int c);
unsigned long	abs_long(long c);

char			min_chr(char a, char b);
short			min_short(short a, short b);
int				min_int(int a, int b);
long			min_long(long a, long b);

char			max_chr(char a, char b);
short			max_short(short a, short b);
int				max_int(int a, int b);
long			max_long(long a, long b);

int				ft_rand(void);
float			ft_randf(void);

t_vec3			random_on_sphere(void);
t_vec3			random_in_hemisphere(const t_vec3 *normal);

#endif
