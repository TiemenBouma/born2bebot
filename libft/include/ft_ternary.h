#ifndef FT_TERNARY_H
# define FT_TERNARY_H

# include <stdbool.h>

char				ter_char(bool condition, char if_true, char if_false);
short				ter_short(bool condition, short if_true, short if_false);
int					ter_int(bool condition, int if_true, int if_false);
long				ter_long(bool condition, long if_true, long if_false);
long long			ter_llong(bool condition, long long if_true,
						long long if_false);

unsigned char		ter_uchar(bool condition, unsigned char if_true,
						unsigned char if_false);
unsigned short		ter_ushort(bool condition, unsigned short if_true,
						unsigned short if_false);
unsigned int		ter_uint(bool condition, unsigned int if_true,
						unsigned int if_false);
unsigned long		ter_ulong(bool condition, unsigned long if_true,
						unsigned long if_false);
unsigned long long	ter_ullong(bool condition, unsigned long long if_true,
						unsigned long long if_false);

void				*ter_ptr(bool condition, void *if_true, void *if_false);
float				ter_float(bool condition, float if_true, float if_false);

#endif