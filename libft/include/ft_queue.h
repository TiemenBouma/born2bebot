#ifndef FT_QUEUE_H
# define FT_QUEUE_H

# include "ft_list.h"

typedef struct s_queue
{
	void	*list;
	size_t	list_size;
	size_t	data_size;

	size_t	low_index;
	size_t	count;
}	t_queue;

bool	queue_init(t_queue *queue, size_t data_size) \
__attribute__((warn_unused_result));

t_queue	*queue_new(size_t data_size);

void	queue_un_init(t_queue *queue, t_free_values free_func);
void	queue_free(t_queue *queue, t_free_values free_func);

bool	queue_resize(t_queue *queue, size_t new_list_size);

void	*queue_peek(t_queue *queue);
void	*queue_pop(t_queue *queue);

bool	queue_push(t_queue *queue, void *ptr) \
__attribute__((warn_unused_result));

#endif