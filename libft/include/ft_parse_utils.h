/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_parse_utils.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/26 16:59:14 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/08/08 14:46:08 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_UTILS_H
# define FT_PARSE_UTILS_H

# include <stdbool.h>
# include "ft_vec3.h"

void	skip_digits(const char *str, int *current);
bool	skip_char(const char *str, int *current, char chr);
void	skip_whitespace(const char *str, int *current);

bool	read_int(const char *str, int *current, int *value);
bool	read_llong(const char *str, int *current, long long *value);
bool	read_float(const char *str, int *current, float *value);
bool	read_vec3(const char *str, int *current, char seperator, t_vec3 *vec3);
bool	read_vec3_unit(const char *str, int *current,
			char seperator, t_vec3 *vec3);

#endif
