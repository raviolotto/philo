# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcardina <succosopompelmo>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 15:33:33 by jcardina          #+#    #+#              #
#    Updated: 2023/09/29 17:09:57 by jcardina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --silent

NAME = philosopher

SRC = \
	philo.c\
	check.c\
	utils.c\
	init.c\

OBJ = $(SRC:%.c=%.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -pthread -g -o philosopher
	@echo "\033[32mcompiled\033[0m"

clean:
	rm -f $(OBJ)
	@echo "\033[33mno sauce\033[0m"

fclean: clean
	rm -f $(NAME)
	@echo "\033[33m& no name\033[0m"

re: fclean all

.PHONY:		all clean fclean re
