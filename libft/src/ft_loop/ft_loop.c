#include "ft_loop.h"
#include "ft_printf.h"
#include <stdlib.h>

// You removed my for loops, so i semi-added them back in
// usage:
//	int i = -1;
//	while (loop_i(5, &i))
//		printf("%i ", i);	// prints: "0 1 2 3 4 "
//	while (loop_i(25, &i))
//		printf("%i ", i);	// prints: "0 1 2 3 4 "

bool	loop_i(int count, int *ref)
{
	(*ref)++;
	if (*ref >= count)
	{
		*ref = -1;
		return (false);
	}
	return (true);
}

bool	loop_si(size_t count, size_t *ref)
{
	(*ref)++;
	if (*ref >= count)
	{
		*ref = -1;
		return (false);
	}
	return (true);
}

// usage:
//	t_list* list = ?;
//	t_struct* i = NULL;
//	while (loop_l(list, &i))
//		printf("%i ", i->data);
//	while (loop_l(list, &i))
//		printf("%i ", i->data);

bool	loop_l(const t_list *list, void **ref)
{
	size_t	index;

	if (*ref == NULL)
	{
		if (list->count > 0)
		{
			*ref = list_index(list, 0);
			return (true);
		}
		return (false);
	}
	index = list_reverse_index_unchecked(list, *ref) + 1;
	if (index >= list->count)
	{
		*ref = NULL;
		return (false);
	}
	*ref = list_index(list, index);
	return (true);
}
