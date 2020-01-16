/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 19:21:11 by zjamali           #+#    #+#             */
/*   Updated: 2020/01/16 19:48:44 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_precision(t_struct *strc)
{
	int i;

	i = 0;
	if (strc->precision <= -1 && strc->point[0] == '1')
		ft_print_convertion(strc);
	else if (strc->point[0] == '1' && strc->precision <= 0)
		return ;
	else if (strc->precision > strc->lengh || strc->precision == -1)
		ft_print_convertion(strc);
	else if (strc->precision <= strc->lengh && strc->precision >= 0)
	{
		while (strc->precision > i)
			ft_putchar(strc->arg.str[i++], &strc->counter);
	}
}

static void	ft_print_min_width(t_struct *strc)
{
	if (strc->flag[0] == '-' || strc->flag[1] == '-')
	{
		ft_print_precision(strc);
		ft_putspaces(strc->min_width - strc->lengh, &strc->counter);
	}
	else
	{
		if (strc->flag[0] == '0')
			ft_putzeros(strc->min_width - strc->lengh, &strc->counter);
		else
			ft_putspaces(strc->min_width - strc->lengh, &strc->counter);
		ft_print_precision(strc);
	}
}

void		ft_print_s(t_struct *strc)
{
	if (strc->precision == -1 && strc->min_width == -1)
		ft_print_convertion(strc);
	else if (strc->precision != -1 || strc->min_width != -1)
	{
		if (strc->len_arg >= strc->precision && strc->precision >= 0)
			strc->lengh = strc->precision;
		else if (strc->len_arg < strc->precision)
			strc->lengh = strc->len_arg;
		else if (strc->precision <= -1)
			strc->lengh = strc->len_arg;
		if (strc->min_width < -1)
		{
			strc->min_width = -strc->min_width;
			strc->flag[0] = '-';
		}
		strc->lengh >= strc->min_width ? ft_print_precision(strc) :
			ft_print_min_width(strc);
	}
}
