# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyungsle <kyungsle@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/09 20:55:44 by kyungsle          #+#    #+#              #
#    Updated: 2022/04/09 21:46:43 by kyungsle         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror
LIBC	= ar rc
LIBR	= ranlib
NAME	= libftprintf.a
SRCS	= ft_printf.c print_address.c print_itoa.c print_char.c print_hex.c print_str_null.c print_uint.c
OBJS	= $(SRCS:.c=.o)
LIBFT	= libft
LIBFT_LIB	= libft.a

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp $(LIBFT)/$(LIBFT_LIB) ./$(NAME)
	$(LIBC) $(NAME) $(OBJS)
	$(LIBR) $(NAME)

all: $(NAME)

clean:
	$(RM) ${OBJS}

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
