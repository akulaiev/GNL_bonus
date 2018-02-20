# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/15 15:25:37 by ybohusev          #+#    #+#              #
#    Updated: 2018/01/15 15:25:38 by ybohusev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_gnl

CC = clang
CC_FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	$(CC) $(CC_FLAGS) -I libft.h -o get_next_line.o -c get_next_line.c
	$(CC) $(CC_FLAGS) -I libft.h -o main.o -c main.c
	$(CC) -o $(NAME) main.o get_next_line.o -I libft.h libft.a

clean:
	rm -Rf get_next_line.o main.o

fclean: clean
	rm -Rf $(NAME)

re: fclean all