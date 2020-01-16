/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 14:45:17 by zjamali           #+#    #+#             */
/*   Updated: 2020/01/16 18:21:14 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *counter)
{
	if (n == -2147483648)
	{
		ft_putchar('2', counter);
		n = 147483648;
	}
	else if (n < 0)
	{
		n = -n;
	}
	if (n <= 9)
	{
		ft_putchar(('0' + n), counter);
	}
	else
	{
		ft_putnbr(n / 10, counter);
		ft_putnbr(n % 10, counter);
	}
}

void	ft_putnbr_i(unsigned int n, int *counter)
{
	if (n <= 9)
	{
		ft_putchar(('0' + n), counter);
	}
	else
	{
		ft_putnbr_i(n / 10, counter);
		ft_putnbr_i(n % 10, counter);
	}
}

void	ft_putnbr_hexa(unsigned int n, int *counter, int xorlx)
{
	if (n < 16)
	{
		if (n <= 9)
			ft_putchar(('0' + n), counter);
		else
		{
			if (xorlx == 0)
				ft_putchar((n + 87), counter);
			else
				ft_putchar((n + 55), counter);
		}
	}
	else
	{
		ft_putnbr_hexa(n / 16, counter, xorlx);
		ft_putnbr_hexa(n % 16, counter, xorlx);
	}
}

void	ft_putnbr_address(long long n, int *counter)
{
	if (n < 16)
	{
		if (n <= 9)
			ft_putchar(('0' + n), counter);
		else
		{
			ft_putchar((n + 87), counter);
		}
	}
	else
	{
		ft_putnbr_address(n / 16, counter);
		ft_putnbr_address(n % 16, counter);
	}
}
