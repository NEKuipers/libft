/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nkuipers <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 17:48:46 by nkuipers       #+#    #+#                */
/*   Updated: 2019/11/05 15:36:27 by nkuipers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	if (s == 0)
		return (NULL);
	new = (char *)malloc(sizeof(char) * len + 1);
	if (new == 0)
		return (NULL);
	j = start;
	while (j < start + len)
	{
		new[i] = s[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}
