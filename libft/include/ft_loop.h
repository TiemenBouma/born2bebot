#ifndef FT_LOOP_H
# define FT_LOOP_H

# include "stdbool.h"
# include "ft_list.h"

bool	loop_i(int count, int *ref);
bool	loop_si(size_t count, size_t *ref);

bool	loop_l(const t_list *list, void **ref);

#endif