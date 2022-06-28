# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyungsle <kyungsle@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/27 01:16:51 by kyungsle          #+#    #+#              #
#    Updated: 2022/06/27 20:32:13 by kyungsle         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror
NAME	= so_long
BONUS	= so_long_bonus
SRCS	= ./mandatory/so_long.c \
		  ./mandatory/image.c \
		  ./mandatory/move.c \
		  ./mandatory/map.c \
		  ./mandatory/game.c \
		  ./mandatory/str_utils.c \
		  ./mandatory/get_next_line.c \
		  ./mandatory/get_next_line_utils.c
SRCSB	= ./bonus/so_long_bonus.c \
		  ./bonus/image_bonus.c \
		  ./bonus/move_bonus.c \
		  ./bonus/map_bonus.c \
		  ./bonus/game_bonus.c \
		  ./bonus/str_utils_bonus.c \
		  ./bonus/get_next_line_bonus.c \
		  ./bonus/get_next_line_utils_bonus.c \
		  ./bonus/ft_itoa.c
OBJS	= $(SRCS:.c=.o)
OBJSB	= $(SRCSB:.c=.o)
MLX_DIR	= ./mlx/

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	make -C $(MLX_DIR)
	$(CC) -o $(NAME) $(OBJS) -L./mlx -lmlx -framework OpenGL -framework AppKit

$(BONUS): $(OBJSB)
	make -C $(MLX_DIR)
	$(CC) -o $(BONUS) $(OBJSB) -L./mlx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

bonus: $(BONUS)

clean:
	make -C $(MLX_DIR) clean
	$(RM) $(OBJS) $(OBJSB)

fclean: clean
	$(RM) $(NAME) $(BONUS)

re: 
	make fclean
	make all

.PHONY: all clean fclean re bonus
