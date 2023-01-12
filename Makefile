# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eamghar <eamghar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/27 15:41:54 by eamghar           #+#    #+#              #
#    Updated: 2023/01/11 18:42:53 by eamghar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER = so_long.h

SRC =	mandatory/backtracking.c\
		mandatory/external_functions1.c\
		mandatory/ft_move_player.c\
		mandatory/get_next_line.c\
		mandatory/parcing.c\
		mandatory/parcing2.c\
		mandatory/print_map.c\
		mandatory/so_long.c\
		
SRC_B = bonus/backtracking.c\
		bonus/enemy.c\
		bonus/external_functions1.c\
		bonus/ft_animate_enemy.c\
		bonus/ft_move_player.c\
		bonus/get_next_line.c\
		bonus/itoa.c\
		bonus/parcing.c\
		bonus/parcing2.c\
		bonus/print_map.c\
		bonus/so_long.c\

NAME = so_long

NAME_B = so_long_bonus

CFLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

bonus : $(NAME_B)

$(NAME) : $(SRC) $(HEADER)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

$(NAME_B) : $(SRC_B) $(HEADER)
	$(CC) $(CFLAGS) $(SRC_B) -o $(NAME_B)

clean:
	rm -rf $(NAME)
	rm -rf $(NAME_B)

fclean: clean

re : fclean all
