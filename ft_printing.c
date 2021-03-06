/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:00:05 by zjamali           #+#    #+#             */
/*   Updated: 2020/01/30 19:26:14 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	intlen(int nbr)
{
	int counter;

	if (nbr == 0)
		return (1);
	counter = 0;
	while (nbr != 0)
	{
		nbr /= 10;
		counter++;
	}
	return (counter);
}

static int	uintlen(unsigned int nbr)
{
	int counter;

	if (nbr == 0)
		return (1);
	counter = 0;
	while (nbr != 0)
	{
		nbr /= 10;
		counter++;
	}
	return (counter);
}

static int	hexlen(long long nbr)
{
	int counter;

	if (nbr == 0)
		return (1);
	counter = 0;
	while (nbr != 0)
	{
		nbr /= 16;
		counter++;
	}
	return (counter);
}

static int	ft_length(t_struct *strc)
{
	int leng;

	leng = 0;
	if (strc->convertion == 'c')
		leng = 1;
	else if (strc->convertion == 's')
		leng = ft_strlen(strc->arg.str);
	else if (strc->convertion == 'd')
		leng = intlen(strc->arg.d);
	else if (strc->convertion == 'i')
		leng = intlen(strc->arg.i);
	else if (strc->convertion == 'u')
		leng = uintlen(strc->arg.u);
	else if (strc->convertion == 'x')
		leng = hexlen((long long)strc->arg.x);
	else if (strc->convertion == 'X')
		leng = hexlen((long long)strc->arg.lx);
	else if (strc->convertion == '%')
		leng = 1;
	else if (strc->convertion == 'p')
		leng = hexlen((long long)strc->arg.p);
	if ((strc->convertion == 'd' && strc->arg.d < 0) ||
			(strc->convertion == 'i' && strc->arg.i < 0))
		strc->sign = 1;
	return (leng);
}

void		ft_printing(t_struct *strc)
{
	if (strc->convertion == 's' && strc->arg.str == NULL)
		strc->arg.str = "(null)";
	strc->len_arg = ft_length(strc);
	if (strc->convertion == 'c')
		ft_print_c(strc);
	else if (strc->convertion == 's')
		ft_print_s(strc);
	else if (strc->convertion == 'd')
		ft_print_d(strc);
	else if (strc->convertion == 'i')
		ft_print_d(strc);
	else if (strc->convertion == 'u')
		ft_print_u(strc);
	else if (strc->convertion == 'x' || strc->convertion == 'X')
		ft_print_x(strc);
	else if (strc->convertion == '%' || strc->convertion == 'p')
		ft_print_p(strc);
}
