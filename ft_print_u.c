/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:49:51 by zjamali           #+#    #+#             */
/*   Updated: 2020/01/29 22:21:38 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_print_precision(t_struct *strc)
{
	if (strc->precision <= -1 && strc->point[0] == '1')
		ft_print_convertion(strc);
	else if (strc->point[0] == '1' && strc->precision <= 0)
	{
		if (strc->arg.d == 0)
			return ;
		else
			ft_print_convertion(strc);
	}
	else if (strc->precision > strc->len_arg || strc->precision == -1)
	{
		ft_putzeros(strc->precision - strc->len_arg, &strc->counter);
		ft_print_convertion(strc);
	}
	else if (strc->precision <= strc->len_arg && strc->precision >= 0)
		ft_print_convertion(strc);
}

static void		ft_print_min_width(t_struct *strc)
{
	if (strc->arg.u == 0 && strc->precision == 0)
		strc->lengh = 0;
	if (strc->flag[0] == '-' || strc->flag[1] == '-')
	{
		ft_print_precision(strc);
		ft_putspaces(strc->min_width - strc->lengh, &strc->counter);
	}
	else
	{
		if (strc->flag[0] == '0' && strc->precision == -1)
			ft_putzeros(strc->min_width - strc->lengh, &strc->counter);
		else
			ft_putspaces(strc->min_width - strc->lengh, &strc->counter);
		ft_print_precision(strc);
	}
}

void			ft_print_u(t_struct *strc)
{
	if (strc->precision == -1 && strc->min_width == -1)
		ft_print_convertion(strc);
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
			strc->flag[0] = '-';
		}
		strc->lengh > strc->min_width ? ft_print_precision(strc) :
			ft_print_min_width(strc);
	}
}
