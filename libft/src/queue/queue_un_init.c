#include "ft_queue.h"
#include <stdlib.h>

void	queue_un_init(t_queue *queue, t_free_values free_func)
{
	void	*ptr;

	while (free_func != NULL)
	{
		ptr = queue_pop(queue);
		if (!ptr)
			break ;
		free_func(ptr);
	}
	free(queue->list);
	queue->list = NULL;
}

void	queue_free(t_queue *queue, t_free_values free_func)
{
	queue_un_init(queue, free_func);
	free(queue);
}
