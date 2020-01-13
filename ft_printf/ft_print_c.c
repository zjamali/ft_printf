/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 21:07:27 by zjamali           #+#    #+#             */
/*   Updated: 2020/01/13 23:43:08 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void ft_print_min_width(t_struct *strc)
{
	if (strc->flag[0] == '-' || strc->flag[1] == '-')
	{
		ft_print_convertion(strc);// need to get how much precision print
		ft_putspaces(strc->min_width - strc->lengh, &strc->counter);
	}
	else
	{
		if (strc->flag[0] == '0')
			ft_putzeros(strc->min_width - strc->lengh, &strc->counter);
		else
			ft_putspaces(strc->min_width - strc->lengh, &strc->counter);
		ft_print_convertion(strc);
	}
}

void	ft_print_c(t_struct *strc)
{
	strc->lengh = 1;
	if (strc->min_width == -1)
		ft_print_convertion(strc);
	else 
		 ft_print_min_width(strc);
}
