#include "ft_list.h"
#include <stdlib.h>
#include "libft.h"

#define DEF_CAP 2

bool	list_init_cap(t_list *list, size_t data_size, size_t cap)
{
	list->data = malloc(data_size * cap);
	if (!list->data)
		return (false);
	list->data_size = data_size;
	list->capacity = cap;
	list->count = 0;
	return (true);
}

bool	list_init(t_list *list, size_t data_size)
{
	return (list_init_cap(list, data_size, DEF_CAP));
}

t_list	*list_new_cap(size_t data_size, size_t cap)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	if (!list_init_cap(list, data_size, cap))
	{
		free(list);
		return (NULL);
	}
	return (list);
}

t_list	*list_new(size_t data_size)
{
	return (list_new_cap(data_size, DEF_CAP));
}

bool	list_set_capacity(t_list *list, size_t capacity)
{
	void	*new_data;

	if (list->count > capacity)
		return (false);
	new_data = malloc(list->data_size * capacity);
	if (!new_data)
		return (false);
	ft_memcpy(new_data, list->data, list->data_size * list->count);
	free(list->data);
	list->data = new_data;
	list->capacity = capacity;
	return (true);
}
