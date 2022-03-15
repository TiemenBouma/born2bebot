/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 13:02:50 by jsimonis      #+#    #+#                 */
/*   Updated: 2021/04/11 22:01:25 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
//#include <unistd.h>

/*
** Counts the number of times that the string s transisions from c to a non c
*/

static int	ft_count_splits(const char *s, char c)
{
	int		num;
	int		curr;

	num = 0;
	curr = 0;
	while (s[curr])
	{
		if (s[curr] != c && (curr == 0 || s[curr - 1] == c))
			num++;
		curr++;
	}
	return (num);
}

static char	**free_pt(char **pt, int from)
{
	while (from > 0)
	{
		from--;
		free(pt[from]);
	}
	free(pt);
	return (NULL);
}

static char	**do_split(const char *s, char **pt, char c, int num_splits)
{
	int		curr_split;
	int		curr;
	int		split_from;
	char	*split;

	curr_split = 0;
	curr = 0;
	while (curr_split < num_splits)
	{
		while (s[curr] == c)
			curr++;
		split_from = curr;
		while (s[curr] != c && s[curr] != '\0')
			curr++;
		split = ft_substr(s, split_from, curr - split_from);
		if (split == NULL)
			return (free_pt(pt, curr_split));
		pt[curr_split] = split;
		curr_split++;
	}
	return (pt);
}

char	**ft_split(const char *s, char c)
{
	int		num;
	char	**pt;

	if (s == NULL)
		s = "";
	num = ft_count_splits(s, c);
	pt = malloc((num + 1) * sizeof(char *));
	if (pt == NULL)
		return (pt);
	pt[num] = NULL;
	return (do_split(s, pt, c, num));
}
