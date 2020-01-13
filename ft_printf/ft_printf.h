/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 10:50:58 by zjamali           #+#    #+#             */
/*   Updated: 2020/01/11 14:44:27 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

typedef union u_argument
{
	char c;
	char *str;
	long long p;
	int i;
	int d;
	unsigned int u;
	unsigned int x;
	unsigned int X;
	char percent;
}				t_arg;

typedef struct s_struct
{
	char *format;
	int counter;
	int index;
	char convertion;
	int precision;
	int sign;
	char point[1];
	int len_arg;
	int lengh;
	char flag[2];
	int min_width;
	t_arg arg;
} 				t_struct;
	/* PRINTING FUNCTIONS */
void ft_printing(t_struct *strc);
void	ft_putchar(char c, int *counter);
void    ft_putstr(char *s, int *counter);
void    ft_putnbr(int n, int *counter);
void    ft_putnbr_i(unsigned int n,int *counter);
void    ft_putnbr_hexa(unsigned int n, int *counter, int xorX );
void    ft_putnbr_address(long long  n, int *counter);

	/* PARSING FUNCTIONS */
int ft_parse_format(char *format, t_struct *strc,va_list *avlist);
	/* UTILS FUNCTIONS */
int             ft_atoi(const char *str);
size_t      ft_strlen(const char *s);
char        *ft_strdup(const char *s1);
char        *ft_strchr(const char *s, int c);
int     ft_isalpha(int c);
int     ft_isalnum(int c);


int ft_printf(const char *format, ...);

#endif
