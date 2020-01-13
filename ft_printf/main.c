/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 20:55:26 by zjamali           #+#    #+#             */
/*   Updated: 2020/01/13 17:45:03 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

#define txt "%10.s",1000

int main()
{
	int retur = 0;
	int r = 0;
//	retur = ft_printf(txt);
//	printf("{%d}\n",retur);
	r = printf("%10.s","JDELE");
	printf("{%d}\n",r);
	return 0;
}
