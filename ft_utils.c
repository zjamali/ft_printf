/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 10:21:21 by zjamali           #+#    #+#             */
/*   Updated: 2020/01/06 10:28:56 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t      ft_strlen(const char *s)
{
	size_t counter;

	counter = 0;
	while (*s != '\0')
	{
		counter++;
		s++;
	}
	return (counter);
}
char        *ft_strdup(const char *s1)
{
	size_t  size;
	char    *s2;

	size = ft_strlen(s1);
	if (!(s2 = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	else
	{
		while (*s1)
		{
			*s2 = *s1;
			s1++;
			s2++;
		}
		*s2 = '\0';
		return (s2 - size);
	}
}

char        *ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return ((char*)s + i);
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	return (NULL);
}

int     ft_isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	return (0);
}

int     ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

