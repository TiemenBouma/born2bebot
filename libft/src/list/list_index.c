#include "ft_list.h"

void	*list_index_unchecked(const t_list *list, size_t index)
{
	return (list->data + index * list->data_size);
}

void	*list_index(const t_list *list, size_t index)
{
	if (index >= list->count)
		return (NULL);
	return (list->data + index * list->data_size);
}

// data = list->data + index * list->data_size;
// solve for index:
// data - list->data = index * list->data_size;
// (data - list->data)/list->data_size = index;

bool	list_contains(const t_list *list, const void *data)
{
	return (data >= list->data
		&& data <= list->data + list->data_size * (list->count - 1));
}

size_t	list_reverse_index_unchecked(const t_list *list, const void *data)
{
	return ((data - list->data) / list->data_size);
}
