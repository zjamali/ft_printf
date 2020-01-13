/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 20:47:28 by zjamali           #+#    #+#             */
/*   Updated: 2020/01/13 20:58:02 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_convertion(t_struct *strc)
{
	if (strc->convertion == 'c')
		ft_putchar(strc->arg.c, &strc->counter);
	else if (strc->convertion == 's')
		ft_putstr(strc->arg.str, &strc->counter);
	else if (strc->convertion == 'd')
		ft_putnbr(strc->arg.d, &strc->counter);
	else if (strc->convertion == 'i')
		ft_putnbr(strc->arg.i, &strc->counter);
	else if (strc->convertion == 'u')
		ft_putnbr_i(strc->arg.u, &strc->counter);
	else if (strc->convertion == 'x')
		ft_putnbr_hexa(strc->arg.x, &strc->counter, 0);
	else if (strc->convertion == 'X')
		ft_putnbr_hexa(strc->arg.x, &strc->counter, 1);
	else if (strc->convertion == '%')
		ft_putchar(strc->arg.percent, &strc->counter);
	else if (strc->convertion == 'p')
	{
		ft_putstr("0x", &strc->counter);
		ft_putnbr_address(strc->arg.p, &strc->counter);
	}
}

void	ft_putspaces(int nbr, int *counter)
{
	while (nbr > 0)
	{
		ft_putchar(' ', counter);
		nbr--;
	}
}

void	ft_putzeros(int nbr, int *counter)
{
	while (nbr > 0)
	{
		ft_putchar('0', counter);
		nbr--;
	}
}
