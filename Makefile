# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/17 19:16:04 by rel-bour          #+#    #+#              #
#    Updated: 2021/06/22 11:40:24 by rel-bour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc 

CFLAGS = -Wall -Wextra -Werror   

SRC = main.c ft_operation.c ft_sort.c ft_split.c ft_sort_part1.c ft_sort_part2.c\
		ft_atoi.c ft_sort_part3.c
	
all : $(NAME)

$(NAME): $(SRC)
	@$(CC) $(SRC) -o $(NAME)
clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)
re:	fclean all