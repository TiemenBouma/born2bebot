#include <stdbool.h>

void	*ter_ptr(bool condition, void *if_true, void *if_false)
{
	if (condition)
		return (if_true);
	return (if_false);
}
