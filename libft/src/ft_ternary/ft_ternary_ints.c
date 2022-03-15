#include <stdbool.h>

char	ter_char(bool condition, char if_true, char if_false)
{
	if (condition)
		return (if_true);
	return (if_false);
}

short	ter_short(bool condition, short if_true, short if_false)
{
	if (condition)
		return (if_true);
	return (if_false);
}

int	ter_int(bool condition, int if_true, int if_false)
{
	if (condition)
		return (if_true);
	return (if_false);
}

long	ter_long(bool condition, long if_true, long if_false)
{
	if (condition)
		return (if_true);
	return (if_false);
}

long long	ter_llong(bool condition, long long if_true, long long if_false)
{
	if (condition)
		return (if_true);
	return (if_false);
}
