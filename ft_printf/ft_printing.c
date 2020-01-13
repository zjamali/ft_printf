/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:00:05 by zjamali           #+#    #+#             */
/*   Updated: 2020/01/13 17:38:56 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_print_convertion(t_struct *strc)
{
	if (strc->convertion == 'c')
		ft_putchar(strc->arg.c,&strc->counter);
	else if (strc->convertion == 's')
		ft_putstr(strc->arg.str,&strc->counter);
	else if (strc->convertion == 'd')
		ft_putnbr(strc->arg.d,&strc->counter);
	else if (strc->convertion == 'i')
		ft_putnbr(strc->arg.i,&strc->counter);
	else if (strc->convertion == 'u')
		ft_putnbr_i(strc->arg.u,&strc->counter);
	else if (strc->convertion == 'x')
		ft_putnbr_hexa(strc->arg.x,&strc->counter,0);
	else if (strc->convertion == 'X')
		ft_putnbr_hexa(strc->arg.x,&strc->counter,1);
	else if (strc->convertion == '%')
		ft_putchar(strc->arg.percent,&strc->counter);
	else if (strc->convertion == 'p')
	{
		ft_putstr("0x",&strc->counter);
		ft_putnbr_address(strc->arg.p,&strc->counter);
	}
}

int intlen(int nbr)
{
	int counter;

	counter = 0;
	if(nbr < 0) //if nbr is negative
		counter++;
	while(nbr != 0)
	{
		nbr /= 10;
		counter++;
	}
	return counter;
}

int hexlen(long long nbr)
{
	int counter;

	counter = 0;

	if (nbr != 0)
	{
		nbr /= 16;
		counter++;	
	}
	return counter;
}
int ft_length(t_struct *strc)
{
	int leng;
	if (strc->convertion == 'c')
		leng = 1;
	else if (strc->convertion == 's')
		leng = ft_strlen(strc->arg.str);
	else if (strc->convertion == 'd')
		leng = intlen(strc->arg.d);
	else if (strc->convertion == 'i')
		leng = intlen(strc->arg.i);
	else if (strc->convertion == 'u')
		leng = intlen(strc->arg.u);
	else if (strc->convertion == 'x')
		leng = hexlen((long long)strc->arg.x);
	else if (strc->convertion == 'X')
		leng = hexlen((long long)strc->arg.X);
	else if (strc->convertion == '%')
		leng = 1;
	else if (strc->convertion == 'p')
		leng = hexlen((long long)strc->arg.p) + 2; // 2 for len of 0x
	if (strc->convertion == 'd' && strc->arg.d < 0)
		strc->sign = 1; //// sign if int is negative
	return leng;
}
void ft_putspaces(int nbr,int *counter)
{
	while(nbr > 0)
	{
		ft_putchar(' ',counter);
		nbr--;
	}
}

void ft_putzeros(int nbr,int *counter)
{
	while(nbr > 0)
	{
		ft_putchar('0',counter);
		nbr--;
	}
}

int ft_print_precision(t_struct *strc)
{
	int i;
	i = 0;
	if (strc->precision <= -1 && strc->point[0] == '1')
		ft_print_convertion(strc);
	else if (strc->point[0] == '1' && strc->precision <= 0)
		return i;
	else if (strc->precision > strc->lengh  || strc->precision == -1)
		ft_print_convertion(strc);
	else if (strc->precision <= strc->lengh 	&& strc->precision >= 0)
	{
		while (strc->precision > i)
			ft_putchar(strc->arg.str[i++],&strc->counter);
	}	
	return i;
}
void ft_print_min_width(t_struct *strc)
{
	if (strc->flag[0] == '-' || strc->flag[1] == '-' /*|| strc->min_width > -1*/ )
	{	
		ft_print_precision(strc); // need to get how much precision print
		ft_putspaces(strc->min_width - strc->lengh,&strc->counter);
	}
	else 
	{
		if (strc->flag[0] == '0')
				ft_putzeros(strc->min_width - strc->lengh,&strc->counter);
		else
				ft_putspaces(strc->min_width - strc->lengh,&strc->counter);
		ft_print_precision(strc);
	}
}
void ft_printing(t_struct *strc)
{
	if (strc->convertion == 's' && strc->arg.str == NULL) //// if arguments ==  NULL
		strc->arg.str = "(null)";

	strc->len_arg = ft_length(strc); /// calcule the length of arguments
	if (strc->precision == -1 && strc->min_width == -1)
		ft_print_convertion(strc);
	else if (strc->precision != -1 || strc->min_width != -1)
	{
		/*************** s *************************/
		if (strc->len_arg >= strc->precision && strc->precision >= 0)
			strc->lengh = strc->precision;
		else if (strc->len_arg < strc->precision)
			strc->lengh = strc->len_arg;
		else if (strc->precision <= -1)
			strc->lengh = strc->len_arg;
		if (strc->min_width <  -1)
		{
			strc->min_width = -strc->min_width;
			strc->flag[0] = '-';
		}
		printf("{{{{{{%d}}}}}}",strc->lengh);
		strc->lengh >= strc->min_width ? ft_print_precision(strc) : ft_print_min_width(strc);
	}
}
