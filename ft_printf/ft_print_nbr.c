/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 14:45:17 by zjamali           #+#    #+#             */
/*   Updated: 2020/01/10 20:27:01 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *counter)
{

	if (n == -2147483648)
	{
		ft_putchar('-', counter);
		ft_putchar('2', counter);
		n = 147483648;
	}
	else if (n < 0)
	{
		ft_putchar('-', counter);
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

void    ft_putnbr_i(unsigned int n,int *counter)
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

void    ft_putnbr_hexa(unsigned int n, int *counter, int xorX )
{

	if (n < 16)
	{
		if (n <= 9)
			ft_putchar(('0' + n), counter);
		else
		{
			if (xorX == 0)
				ft_putchar((n + 87), counter);
			else
				ft_putchar((n + 55), counter);
		}
	}
	else
	{
		ft_putnbr_hexa(n / 16, counter,xorX);
		ft_putnbr_hexa(n % 16, counter,xorX);
	}
}

void    ft_putnbr_address(long long  n, int *counter)
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
