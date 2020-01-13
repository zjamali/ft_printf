/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 21:15:56 by zjamali           #+#    #+#             */
/*   Updated: 2020/01/05 17:50:20 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int ft_printf(const char *format, ...)
{
	int numcharprinted;
	va_list avlist;

	numcharprinted = 0;
	va_start(avlist,format); //inisialisation de list

	/*printing format--start--*/
	while(*format != '\0')
	{
		if (*format != '%')
		{
			ft_putchar_fd(*format,&numcharprinted);
		}
		else
		{
			format++;
			if (*format == 'c')
			{
				char chartoprint;
				chartoprint = (char)va_arg(avlist,int);
				ft_putchar_fd(chartoprint,&numcharprinted);
			}
			else if (*format == 's')
			{
				char *strtoprint;
				strtoprint = va_arg(avlist,char*);
				ft_putstr_fd(strtoprint, 1);
				numcharprinted+=ft_strlen(strtoprint);
			}
			else if (*format == 'd' || *format == 'i' || *format == '*')
			{
				int num;
				num = va_arg(avlist,int);
				ft_putnbr_fd(num,1);
				numcharprinted+= ft_strlen(ft_itoa(num));
			}
			else if (*format == 'u')
			{
				unsigned int num;
				num = va_arg(avlist,unsigned int);	
				ft_putnbr_i(num,1);
				numcharprinted+= ft_strlen(ft_itoa(num));
			}
			else if (*format == 'x')
			{
				int re;
				unsigned int num;
				num = va_arg(avlist,unsigned int);
				re = ft_puthex(num,1,0);
				numcharprinted+= re;
			}
			else if (*format == 'X')
			{
				int re;
				unsigned int num;
				num = va_arg(avlist,unsigned int);
				re = ft_puthex(num,1,1);
				numcharprinted+= re;
			}
			else if (*format == 'p')
			{
				int re;
				long long num;
				ft_putchar_fd('0',1);
				ft_putchar_fd('x',1);
				numcharprinted+= 2;
				num = va_arg(avlist,long long);
				re = ft_putaddress(num,1,0);
				numcharprinted+= re;
			}
			else if (*format == '%')
			{
				ft_putchar_fd('%',1);
				numcharprinted++;
			}
		}
		format++;
		/*printing format--end--*/
	}
	return numcharprinted;
}
