/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 16:59:40 by zjamali           #+#    #+#             */
/*   Updated: 2020/01/29 21:57:22 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_inicialise(t_struct *strc, int n)
{
	if (n == 0)
	{
		strc->format = NULL;
		strc->counter = 0;
		strc->index = 0;
	}
	strc->convertion = -1;
	strc->precision = -1;
	strc->sign = 0;
	strc->point[0] = '0';
	strc->len_arg = 0;
	strc->lengh = 0;
	strc->flag[0] = '1';
	strc->flag[1] = '1';
	strc->min_width = -1;
	strc->arg.str = NULL;
	strc->sign_value = 0;
}

static int	ft_check_convertion(char *format)
{
	int i;

	i = 0;
	if (format[i + 1] == '\0')
		return (0);
	i++;
	while (format[i] != '\0')
	{
		if (ft_strchr("cspdiuxX%", format[i]))
			return (1);
		else if (format[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}

int			ft_printf(const char *format, ...)
{
	t_struct	strc;
	va_list		avlist;

	va_start(avlist, format);
	ft_inicialise(&strc, 0);
	strc.format = (char*)format;
	while (format[strc.index])
	{
		if (strc.format[strc.index] != '%')
			ft_putchar(strc.format[strc.index], &strc.counter);
		else if (strc.format[strc.index] == '%' && ft_strchr(
					"0123456789*-+ .cspdiuxX%", strc.format[strc.index + 1]))
		{
			if (ft_check_convertion(strc.format) == 0)
				break ;
			ft_inicialise(&strc, 1);
			strc.index += ft_parse_format(&strc.format[strc.index],
					&strc, &avlist);
			ft_printing(&strc);
		}
		strc.index++;
	}
	va_end(avlist);
	return (strc.counter);
}
