/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 12:49:55 by zjamali           #+#    #+#             */
/*   Updated: 2020/01/29 23:16:57 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_printf_pr(t_struct *strc)
{
	if (strc->min_width > 1 && strc->arg.p == 0 && strc->point[0] != '0')
		strc->len_arg = 0;
	if (strc->len_arg != 0)
	{
		if (strc->len_arg > strc->precision)
			strc->lengh = strc->len_arg;
		else
			strc->lengh = strc->precision;
	}
	ft_putspaces(strc->min_width - strc->lengh - 2, &strc->counter);//  for 0x
	ft_putstr("0x", &strc->counter);
	ft_putzeros(strc->precision - strc->lengh, &strc->counter);
	if (strc->arg.p == 0 && strc->precision == 0)
		return ;
	else
		ft_putnbr_address(strc->arg.p, &strc->counter);
}

static void		ft_printp(t_struct *strc)
{
	if (strc->flag[0] == '-' || strc->flag[1] == '-')
	{
		ft_putstr("0x", &strc->counter);
		ft_putzeros(strc->precision - strc->len_arg, &strc->counter);
		if (strc->arg.p == 0 && strc->precision == 0)
		{
			ft_putspaces(strc->min_width - 2, &strc->counter);
			return ;
		}
		else
			ft_putnbr_address(strc->arg.p, &strc->counter);
		ft_putspaces(strc->min_width - strc->len_arg - 2, &strc->counter);//  for 0x
	}
	else
	{
		if (strc->min_width != -1 || strc->precision != -1)
			ft_printf_pr(strc);
		else
		{
			ft_putspaces(strc->min_width - strc->len_arg - strc->precision,
					&strc->counter);
			ft_putstr("0x", &strc->counter);
			ft_putnbr_address(strc->arg.p, &strc->counter);
		}
	}
}

void			ft_print_p(t_struct *strc)
{
	if (strc->convertion == '%')
	{
		if (strc->flag[0] == '-' || strc->flag[1] == '-')
		{
			ft_print_convertion(strc);
			ft_putspaces(strc->min_width - strc->len_arg, &strc->counter);
		}
		else
		{
			if (strc->flag[0] == '0')
				ft_putzeros(strc->min_width - strc->len_arg, &strc->counter);
			else
				ft_putspaces(strc->min_width - strc->len_arg, &strc->counter);
			ft_print_convertion(strc);
		}
	}
	else if (strc->convertion == 'p')
		ft_printp(strc);
}
