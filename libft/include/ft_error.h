/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_error.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jasper <jasper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/23 11:26:48 by jasper        #+#    #+#                 */
/*   Updated: 2021/01/31 16:28:29 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

# include <stdbool.h>

char			*get_last_error(void);
void			set_error(char *error_msg, bool should_free);
void			clear_error(void);

#endif
