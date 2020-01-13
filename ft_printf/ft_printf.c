/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 16:59:40 by zjamali           #+#    #+#             */
/*   Updated: 2020/01/13 23:10:46 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_inicialise(t_struct *strc, int n)
{
	if (n == 0)
	{
		strc->format = NULL;
		strc->counter = 0;
		strc->index = 0;
	}
		strc->convertion = -1;
		strc->precision = -1;
		strc->sign = 0; // 0-> P // 1 -> N
		strc->point[0] = '0'; 
		strc->len_arg = 0;
		strc->lengh = 0;
		strc->flag[0] = '1';
		strc->flag[1] = '1';
		strc->min_width = -1;
		strc->arg.str = NULL;
}

int ft_printf(const char *format, ...)
{
	t_struct strc;
	va_list avlist;

	va_start(avlist,format); //start the avlist
	ft_inicialise(&strc,0); // inicialise the structure
	strc.format = (char*)format;

	while(format[strc.index])
	{
		if (strc.format[strc.index] != '%')
				ft_putchar(strc.format[strc.index],&strc.counter);
		else if (strc.format[strc.index] == '%' && 
				ft_strchr("0123456789*-+ .cspdiuxX%",strc.format[strc.index + 1]))
		{
			ft_inicialise(&strc,1);
			strc.index += ft_parse_format(&strc.format[strc.index],&strc,&avlist);
			/*printf("\n**************************************************\n");
			printf("strc->counter {%d}\n",strc.counter);
			printf("strc->format {%s}\n",strc.format);
			printf("strc->convertion {%c}\n",strc.convertion);
			printf("strc->precision {%d}\n",strc.precision);
			printf("strc->min_width {%d}\n",strc.min_width);
			printf("strc->sign {%d}\n",strc.sign);
			printf("strc->point {%c}\n",strc.point[0]);
			printf("strc->len_arg {%d}\n",strc.len_arg);
			printf("strc->lengh {%d}\n",strc.lengh);
			printf("strc->flag {%c%c}\n",strc.flag[0],strc.flag[1]);
			printf("*************************************************\n");*/
			ft_printing(&strc);
		}
		strc.index++;
	}
	va_end(avlist);
	return strc.counter;
}
