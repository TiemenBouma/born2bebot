#include "ft_queue.h"
#include "libft.h"

void	*queue_peek(t_queue *queue)
{
	if (queue->count == 0)
		return (NULL);
	return (queue->list + queue->low_index * queue->data_size);
}

// Increment low index
// Wrap arround

void	*queue_pop(t_queue *queue)
{
	void	*result;

	result = queue_peek(queue);
	if (!result)
		return (NULL);
	queue->low_index++;
	if (queue->low_index == queue->list_size)
		queue->low_index = 0;
	queue->count--;
	return (result);
}

bool	queue_push(t_queue *queue, void *ptr)
{
	int	InsertIndex;

	if (queue->count == queue->list_size && !queue_resize(queue, queue
			->list_size * 2))
		return (false);
	InsertIndex = (queue->low_index + queue->count) % queue->list_size;
	ft_memcpy(queue->list + InsertIndex * queue->data_size, ptr, queue
		->data_size);
	queue->count++;
	return (true);
}
