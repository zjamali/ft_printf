/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 20:55:26 by zjamali           #+#    #+#             */
/*   Updated: 2020/01/16 15:09:14 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

#define txt "%0*d", -7, -5

int main()
{
	int retur = 0;
	int r = 0;
	retur = ft_printf("%-05");
	printf("{%d}\n",retur);
	r = printf("%05");
	printf("{%d}\n",r);
	return 0;
}
