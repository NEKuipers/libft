/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nkuipers <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 13:31:09 by nkuipers       #+#    #+#                */
/*   Updated: 2019/11/05 10:31:58 by nkuipers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t position;

	i = 0;
	j = 0;
	if (!(needle))
		return ((char *)haystack);
	while (haystack && i < len)
	{
		while (haystack[i] != needle[j] && i < len)
			i++;
		position = i;
		while (haystack[i] == needle[j] && haystack && needle)
		{
			i++;
			j++;
		}
	}
	if (haystack[i - 1] == needle[j - 1] && needle == '\0')
		return ((char *)&haystack[position]);
	else
		return (NULL);
}
