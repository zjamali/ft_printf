/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:00:05 by zjamali           #+#    #+#             */
/*   Updated: 2020/01/13 23:50:18 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
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
void ft_printing(t_struct *strc)
{
	if (strc->convertion == 's' && strc->arg.str == NULL) //// if arguments ==  NULL
		strc->arg.str = "(null)";
	strc->len_arg = ft_length(strc); /// calcule the length of arguments
	if (strc->convertion == 'c')
		ft_print_c(strc);
	if (strc->convertion == 's')
		ft_print_s(strc);
/*	else if (strc->convertion == 'd')
		leng = intlen(strc->arg.d);
	else if (strc->convertion == 'i')
		leng = intlen(strc->arg.i);
		*/
	/*else if (strc->convertion == 'u')
		ft_print_u(strc);
	
	else if (strc->convertion == 'x')
		leng = hexlen((long long)strc->arg.x);
	else if (strc->convertion == 'X')
		leng = hexlen((long long)strc->arg.X);
	else if (strc->convertion == '%')
		leng = 1;
	else if (strc->convertion == 'p')
		leng = hexlen((long long)strc->arg.p) + 2; // 2 for len of 0x
	if (strc->convertion == 'd' && strc->arg.d < 0)
		strc->sign = 1; //// sign if int is negative*/
}
