#include "ft_queue.h"
#include <stdlib.h>
#include "libft.h"

bool	queue_init(t_queue *queue, size_t data_size)
{
	queue->list_size = 16;
	queue->list = malloc(data_size * queue->list_size);
	if (!queue->list)
		return (NULL);
	queue->low_index = 0;
	queue->count = 0;
	queue->data_size = data_size;
	return (true);
}

t_queue	*queue_new(size_t data_size)
{
	t_queue	*queue;

	queue = malloc(sizeof(t_queue));
	if (!queue)
		return (NULL);
	if (!queue_init(queue, data_size))
	{
		free(queue);
		return (NULL);
	}
	return (queue);
}

bool	queue_resize(t_queue *queue, size_t new_list_size)
{
	size_t			i;
	unsigned char	*new_list;
	unsigned char	*old_list;

	if (new_list_size < queue->count)
		return (false);
	new_list = malloc(queue->data_size * new_list_size);
	if (!new_list)
		return (false);
	old_list = queue->list;
	i = 0;
	while (i < queue->count * queue->data_size)
	{
		new_list[i] = old_list[(i + queue->low_index * queue->data_size)
			% (queue->list_size * queue->data_size)];
		i++;
	}
	free(queue->list);
	queue->list = new_list;
	queue->low_index = 0;
	queue->list_size = new_list_size;
	return (true);
}
