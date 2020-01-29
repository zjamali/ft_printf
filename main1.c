/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:25:25 by zjamali           #+#    #+#             */
/*   Updated: 2020/01/29 23:18:15 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>


//#define TST "|%c %-5.9s %20d %30.15u %-59.19x |\n",'a',(void*)0,-5949,-595995959, -595959
//#define TST "|%*.*u|\n",1,0,0 
#define TST "|%-15.-20p|\n",(void*)0
int main()
{
	int x = ft_printf(TST);
	int y = printf(TST);

	printf("|ft ====> %d|\t|pr ====>%d|",x,y);
	//printf("|%d|\n", ft_printf("%10.s",5));
	//printf("|%d|\n", printf("%10.s",5));
}
