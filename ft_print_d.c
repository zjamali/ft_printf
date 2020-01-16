/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 20:12:22 by zjamali           #+#    #+#             */
/*   Updated: 2020/01/16 16:18:10 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void ft_printsign(t_struct *strc)
{
	if (strc->sign_value == 1)
	{
		strc->sign_value = 0;
		ft_putchar('-',&strc->counter);
	}
}

static void ft_print_precision(t_struct *strc)
{
	//if (strc->min_width <= strc->lengh)
	ft_printsign(strc);
	if (strc->precision <= -1 && strc->point[0] == '1')
	{
		ft_print_convertion(strc);
	}
	else if (strc->point[0] == '1' && strc->precision <= 0)
		return ;
	else if (strc->precision > strc->len_arg  || strc->precision == -1)
	{
		ft_putzeros(strc->precision - strc->len_arg,&strc->counter);
		ft_print_convertion(strc);
	}
	else if (strc->precision <= strc->len_arg && strc->precision >= 0)
		ft_print_convertion(strc);
}

static void ft_print_min_width(t_struct *strc)
{
//	ft_printsign(strc);
	if (strc->arg.u == 0 && strc->precision == 0)
		strc->lengh = 0;
	if (strc->flag[0] == '-' || strc->flag[1] == '-')
	{
		ft_printsign(strc);
		ft_print_precision(strc);
		ft_putspaces(strc->min_width - strc->lengh - strc->sign, &strc->counter);
	}
	else
	{
		/*if (strc->flag[0] == '0' && strc->precision == -1)*/
		if (strc->flag[0] == '0' && strc->precision <= -1)
		{
			ft_printsign(strc);
			ft_putzeros(strc->min_width - strc->lengh - strc->sign, &strc->counter);
		}
		else
		{
			ft_putspaces(strc->min_width - strc->lengh - strc->sign, &strc->counter);
			ft_printsign(strc);
		}
		ft_print_precision(strc);
	}
}

void    ft_print_d(t_struct *strc)
{
	if (strc->addspace == 1 && strc->sign == 0)
		ft_putchar(' ',&strc->counter);
	if (strc->precision == -1 && strc->min_width == -1)
	{
		if (strc->sign == 1)
			ft_putchar('-',&strc->counter);
		ft_print_convertion(strc);
	}
	else
	{
		if (strc->len_arg >= strc->precision && strc->precision >= 0)
			strc->lengh = strc->len_arg;
		else if (strc->len_arg < strc->precision)
			strc->lengh = strc->precision;
		else if (strc->precision <= -1)
			strc->lengh = strc->len_arg;
		if (strc->min_width < -1)
		{
			strc->min_width = -strc->min_width;
			strc->flag[1] = strc->flag[0];
			strc->flag[0] = '-';
		}
		if (strc->arg.d < 0)
		{
			strc->sign_value = 1;
			strc->arg.d < 0 ? strc->arg.d  = -strc->arg.d: strc->arg.d;
		}
		strc->lengh >= strc->min_width ? ft_print_precision(strc) : ft_print_min_width(strc);
	}
}

