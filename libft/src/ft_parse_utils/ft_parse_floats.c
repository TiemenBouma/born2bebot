#include "ft_parse_utils.h"
#include "ft_error.h"
#include "libft.h"
#include "ft_ternary.h"
#include <limits.h>

bool	read_float(const char *str, int *current, float *value)
{
	int		start;
	bool	is_negative;
	float	worth;

	start = *current;
	*value = 0;
	is_negative = skip_char(str, current, '-');
	while (ft_isdigit(str[*current]))
	{
		*value = *value * 10 + str[*current] - '0';
		(*current)++;
	}
	if (skip_char(str, current, '.'))
	{
		worth = 0.1f;
		while (ft_isdigit(str[*current]))
		{
			*value += (str[*current] - '0') * worth;
			worth /= 10;
			(*current)++;
		}
	}
	if (is_negative)
		*value = - *value;
	return (start != *current);
}

bool	read_vec3(const char *str, int *current, char seperator, t_vec3 *o_vec3)
{
	if (!read_float(str, current, &o_vec3->x) || !skip_char(str, current,
			seperator))
		return (false);
	if (!read_float(str, current, &o_vec3->y) || !skip_char(str, current,
			seperator))
		return (false);
	if (!read_float(str, current, &o_vec3->z))
		return (false);
	return (true);
}

bool	read_vec3_unit(const char *str, int *current, char seperator,
	t_vec3 *o_vec3)
{
	if (!read_vec3(str, current, seperator, o_vec3))
		return (false);
	if (vec3_magnitude_sqr(o_vec3) < 0.001)
		return (false);
	vec3_normalize(o_vec3, o_vec3);
	return (true);
}
