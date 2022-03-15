#include "ft_list.h"

void	list_foreach(const t_list *list, const t_foreach_value foreach_value)
{
	size_t	i;

	i = 0;
	while (i < list->count)
	{
		foreach_value(list_index_unchecked(list, i));
		i++;
	}
}

void	list_foreach_data(const t_list *list, void *data,
	const t_foreach_data_value foreach_data_value)
{
	size_t	i;

	i = 0;
	while (i < list->count)
	{
		foreach_data_value(data, list_index_unchecked(list, i));
		i++;
	}
}

void	list_foreach_range(const t_list *list, t_range range,
	const t_foreach_value foreach_value)
{
	size_t	i;

	i = range.start;
	while (i < list->count && i < range.end)
	{
		foreach_value(list_index_unchecked(list, i));
		i++;
	}
}

void	list_foreach_range_data(const t_list *list, void *data, t_range range,
	const t_foreach_data_value foreach_data_value)
{
	size_t	i;

	i = range.start;
	while (i < list->count && i < range.end)
	{
		foreach_data_value(data, list_index_unchecked(list, i));
		i++;
	}
}
