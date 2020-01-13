/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 20:55:26 by zjamali           #+#    #+#             */
/*   Updated: 2020/01/13 23:10:27 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

#define txt "%-1c %-2c %-3c %-5c",'q','w','e','u'

int main()
{
	int retur = 0;
	int r = 0;
	retur = ft_printf(txt);
	printf("{%d}\n",retur);
	r = printf(txt);
	printf("{%d}\n",r);
	return 0;
}
