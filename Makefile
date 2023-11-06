# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcardina <jcardina@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 15:33:33 by jcardina          #+#    #+#              #
#    Updated: 2023/11/06 18:51:02 by jcardina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --silent

NAME = philosopher

SRC = \
	philo.c\
	check.c\
	utils.c\
	routine_utils.c\
	init.c\
	routine.c\

OBJ = $(SRC:%.c=%.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra -pthread -g -fsanitize=thread

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o philosopher
	@echo "\033[32mcompiled\033[0m"

clean:
	rm -f $(OBJ)
	@echo "\033[33mno sauce\033[0m"

fclean: clean
	rm -f $(NAME)
	@echo "\033[33m& no name\033[0m"

re: fclean all

.PHONY:		all clean fclean re
