#include <stdbool.h>

unsigned char	ter_uchar(bool condition, unsigned char if_true,
	unsigned char if_false)
{
	if (condition)
		return (if_true);
	return (if_false);
}

unsigned short	ter_ushort(bool condition, unsigned short if_true,
	unsigned short if_false)
{
	if (condition)
		return (if_true);
	return (if_false);
}

unsigned int	ter_uint(bool condition, unsigned int if_true,
	unsigned int if_false)
{
	if (condition)
		return (if_true);
	return (if_false);
}

unsigned long	ter_ulong(bool condition, unsigned long if_true,
	unsigned long if_false)
{
	if (condition)
		return (if_true);
	return (if_false);
}

unsigned long long	ter_ullong(bool condition, unsigned long long if_true,
	unsigned long long if_false)
{
	if (condition)
		return (if_true);
	return (if_false);
}
