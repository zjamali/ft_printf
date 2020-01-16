/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 14:42:30 by zjamali           #+#    #+#             */
/*   Updated: 2020/01/16 18:23:40 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putchar(char c, int *counter)
{
	write(1, &c, 1);
	*counter += 1;
}

void		ft_putstr(char *s, int *counter)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			ft_putchar(s[i], counter);
			i++;
		}
	}
}

static int	check(int s, int counter, int result)
{
	if (counter > 19)
	{
		if (s > 0)
			return (-1);
		else
			return (0);
	}
	return (s * result);
}

int			ft_atoi(const char *str)
{
	int i;
	int s;
	int result;
	int	counter;

	counter = 0;
	i = 0;
	s = 1;
	result = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == ' '
			|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
		counter++;
	}
	return (check(s, counter, result));
}
