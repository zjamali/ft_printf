# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zjamali <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/13 18:10:01 by zjamali           #+#    #+#              #
#    Updated: 2020/01/16 13:42:54 by zjamali          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libftprintf.a

SRC= ft_parse_format.c	ft_print_str.c	ft_utils.c	\
	 ft_print_nbr.c	ft_printf.c	ft_printing.c	ft_print_s.c	ft_print_conv.c \
	 ft_print_c.c	ft_print_p.c	ft_print_u.c	ft_print_x.c	ft_print_d.c \

INC= ft_printf.h
OBJ= $(SRC:.c=.o)

CFLAGS=  -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	@gcc -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ) 

fclean: clean
	@rm -f $(NAME)

re: fclean all
