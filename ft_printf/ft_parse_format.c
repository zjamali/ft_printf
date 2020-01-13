/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 21:37:38 by zjamali           #+#    #+#             */
/*   Updated: 2020/01/13 23:14:23 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_get_flags(char *format, char *flag)
{
	int			i;
	static int	j;

	i = 0;
	if (j > 1)
		j = 0;
	if (flag[j] == '1' && (format[i] == '-' || format[i] == '0')
			&& format[i] != flag[0] && format[i] != flag[1])
	{
		if (format[i] == '0' && ft_strchr("-*%+", format[i - 1]))
			flag[j++] = '0';
		else if (format[i] == '-')
			flag[j++] = format[i];
		//printf("{{{%d}}\n",j);
	}
}

void			ft_get_arg_convertion(t_struct *strc, va_list *avlist)
{
	if (strc->convertion == 'c')
		strc->arg.c = va_arg(*avlist, int);
	else if (strc->convertion == 's' && strc->precision != 0) //printf not segf if "%10.s,5"
		strc->arg.str = va_arg(*avlist, char*);
	else if (strc->convertion == 'p')
		strc->arg.p = va_arg(*avlist, long long);
	else if (strc->convertion == 'd')
		strc->arg.d = va_arg(*avlist, int);
	else if (strc->convertion == 'i')
		strc->arg.i = va_arg(*avlist, int);
	else if (strc->convertion == 'u')
		strc->arg.u = va_arg(*avlist, unsigned int);
	else if (strc->convertion == 'x')
		strc->arg.x = va_arg(*avlist, unsigned int);
	else if (strc->convertion == 'X')
		strc->arg.X = va_arg(*avlist, unsigned int);
	else if (strc->convertion == '%')
		strc->arg.percent = '%';
}

static void		ft_get_precision(char *format, t_struct *strc, va_list *avlist)
{
	int i;

	i = 0;
	if (ft_strchr("123456789*", format[i]) && (format[i - 1] != '.'
				|| ft_strchr("0123456789*%", format[i - 1])))  // get min_with
	{
		if ((strc->min_width == -1) ||
				(strc->min_width != -1 && format[i - 1]  == '*')) /// %10.*20 it take 20 a minimum widt
		{
			if (format[i] == '*')
				strc->min_width = va_arg(*avlist, int);
			else if (format[i - 2] != '.')
			{
				strc->min_width = ft_atoi(&format[i]);
			}
		}
	}
}

int				ft_parse_format(char *format, t_struct *strc, va_list *avlist)
{
	int i;

	i = 0;
	while (format[i])
	{
		ft_get_flags(&format[i], strc->flag); /// get flags
		if (format[i] == '.') // if there is a point
			strc->point[0] = '1';
		ft_get_precision(&format[i], strc, avlist);
		if (format[i] == '.') // get precision 
		{
			if (format[i + 1] == '*')
				strc->precision = va_arg(*avlist, int);
			else
				strc->precision = ft_atoi(&format[i + 1]);
		}
		if (ft_strchr("cspdiuxX%", format[i]) && i != 0) /// i != 0 to don't get the first % 
		{
			strc->convertion = format[i];
			ft_get_arg_convertion(strc, avlist); //get the arguments of converting 
			break ;
		}
		i++;
	}
	return (i);
}
