/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 10:50:58 by zjamali           #+#    #+#             */
/*   Updated: 2020/01/29 21:49:37 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef union	u_argument
{
	char					c;
	char					*str;
	unsigned long long		p;
	int						i;
	int						d;
	unsigned int			u;
	unsigned int			x;
	unsigned int			lx;
	char					percent;
}				t_arg;

typedef struct	s_struct
{
	char	*format;
	int		counter;
	int		index;
	char	convertion;
	int		precision;
	int		sign;
	char	point[1];
	int		len_arg;
	int		lengh;
	char	flag[2];
	int		min_width;
	int		sign_value;
	t_arg	arg;
}				t_struct;

void			ft_printing(t_struct *strc);
void			ft_putchar(char c, int *counter);
void			ft_putstr(char *s, int *counter);
void			ft_putnbr(int n, int *counter);
void			ft_putnbr_i(unsigned int n, int *counter);
void			ft_putnbr_hexa(unsigned int n, int *counter, int xorlx);
void			ft_putnbr_address(long long n, int *counter);
void			ft_print_s(t_struct *strc);
void			ft_print_c(t_struct *strc);
void			ft_print_p(t_struct *strc);
void			ft_print_u(t_struct *strc);
void			ft_print_x(t_struct *strc);
void			ft_print_d(t_struct *strc);
void			ft_putzeros(int nbr, int *counter);
void			ft_putspaces(int nbr, int *counter);
void			ft_print_convertion(t_struct *strc);
int				ft_parse_format(char *format, t_struct *strc, va_list *avlist);
int				ft_atoi(const char *str);
size_t			ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);
int				ft_printf(const char *format, ...);
#endif
