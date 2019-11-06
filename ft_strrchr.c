/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nkuipers <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 14:11:36 by nkuipers       #+#    #+#                */
/*   Updated: 2019/11/06 11:23:44 by nkuipers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *temp;

	temp = 0;
	while (*s && *s != '\0')
	{
		if (*s == c)
			temp = (char*)s;
		s++;
	}
	if (c == '\0')
		return ((char*)s);
	if (temp != 0)
		return (temp);
	else
		return (0);
}
