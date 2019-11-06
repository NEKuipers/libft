/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nkuipers <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 13:31:09 by nkuipers       #+#    #+#                */
/*   Updated: 2019/11/06 11:00:11 by nkuipers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (haystack[i] == '\0')
		return (0);
	while (haystack != '\0' && i < len)
	{
		if (needle[j] == '\0')
			return ((char *)&haystack[i - j]);
		else if (haystack[i] == needle[j])
			j++;
		else
			j = 0;
		i++;
	}
	if (needle[j] == '\0')
		return ((char *)&haystack[i - j]);
	else
		return (0);
}
