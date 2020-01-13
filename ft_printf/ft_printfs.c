if (strc->convertion == 's')
{
	if(strc->len_arg > strc->min_width)
	{
		if (strc->len_arg < strc->precision || strc->precision == -1)
			ft_putstr(strc->arg.str,&strc->counter);
		else if (strc->len_arg >= strc->precision )
		{
			int i;
			i = 0;
			while (strc->precision > i)
				ft_putchar(strc->arg.str[i++],&strc->counter);
		}
	}
	else if (strc->len_arg < strc->min_width)
	{

		if ((strc->flag[0] == '-' || strc->flag[0] == '0') && strc->flag[1] == '1')
		{
			if (strc->flag[0] == '-')
			{
				if (strc->len_arg < strc->precision || strc->precision == -1)
					ft_putstr(strc->arg.str,&strc->counter);
				else if (strc->len_arg >= strc->precision )
				{
					int i;
					i = 0;
					while (strc->precision > i)
						ft_putchar(strc->arg.str[i++],&strc->counter);
				}
				ft_print_spaces(strc->min_width - strc->len_arg,&strc->counter);
			}
			else if (strc->flag[0] == '0')
			{
				ft_print_zeros(strc->min_width - strc->len_arg,&strc->counter);

				if (strc->len_arg < strc->precision || strc->precision == -1)
					ft_putstr(strc->arg.str,&strc->counter);
				else if (strc->len_arg >= strc->precision )
				{
					int i;
					i = 0;
					while (strc->precision > i)
						ft_putchar(strc->arg.str[i++],&strc->counter);
				}
			}
		}
		else if (strc->flag[0] == '0' && strc->flag[1] == '-')
		{
			if (strc->len_arg < strc->precision || strc->precision == -1)
				ft_putstr(strc->arg.str,&strc->counter);
			else if (strc->len_arg >= strc->precision )
			{
				int i;
				i = 0;
				while (strc->precision > i)
					ft_putchar(strc->arg.str[i++],&strc->counter);
			}

			ft_print_spaces(strc->min_width - strc->len_arg,&strc->counter);
		}
		else if (strc->flag[0] == '1' && strc->flag[1] == '1')
		{
			ft_print_spaces(strc->min_width - strc->len_arg,&strc->counter);

			if (strc->len_arg < strc->precision || strc->precision == -1)
				ft_putstr(strc->arg.str,&strc->counter);
			else if (strc->len_arg >= strc->precision )
			{
				int i;
				i = 0;
				while (strc->precision > i)
					ft_putchar(strc->arg.str[i++],&strc->counter);

