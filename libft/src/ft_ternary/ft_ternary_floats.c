#include <stdbool.h>

float	ter_float(bool condition, float if_true, float if_false)
{
	if (condition)
		return (if_true);
	return (if_false);
}
