/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nkuipers <nkuipers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 13:28:15 by nkuipers       #+#    #+#                */
/*   Updated: 2019/11/05 15:09:04 by nkuipers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		*free_all(int j, char **strings)
{
	while (j != 0)
	{
		free(strings[j]);
		j--;
	}
	free(strings);
	return (NULL);
}

static int		count_segments(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = (s[0] == c ? 0 : 1);
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

static int		seg_length(char const *s, char c, int pos)
{
	int	len;

	len = 0;
	while (s[pos] != '\0' && s[pos] != c)
	{
		pos++;
		len++;
	}
	return (len);
}

static char		**make_strings(char const *s, char c, char **strings)
{
	int		segcount;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	segcount = count_segments(s, c);
	while (s[i] != '\0' && j < segcount)
	{
		k = 0;
		strings[j] = (char *)malloc(sizeof(char) * (seg_length(s, c, i) + 1));
		if (strings[j] == 0)
			return (free_all(j, strings));
		while (s[i] != '\0' && s[i] != c && k < seg_length(s, c, i))
		{
			strings[j][k] = s[i];
			i++;
			k++;
		}
		strings[j][k] = '\0';
		j++;
	}
	strings[j] = NULL;
	return (strings);
}

char			**ft_split(char const *s, char c)
{
	char	**strings;

	if (s == 0)
		return (NULL);
	strings = (char**)malloc(sizeof(char *) * count_segments(s, c) + 1);
	if (!(strings))
		return (NULL);
	strings = make_strings(s, c, strings);
	return (strings);
}
