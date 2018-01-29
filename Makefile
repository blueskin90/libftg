# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toliver <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/12 01:24:53 by toliver           #+#    #+#              #
#    Updated: 2018/01/30 00:23:48 by toliver          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftg.a

FLAGS = -Wall -Wextra -Werror -Ofast

FILES = vector.c

SRC = $(FILES))

SRC_PATH = srcs/

SRCS = $(addprefix $(SRC_PATH),$(SRC))

OBJS = $(SRC:.c=.o)

INCLUDES = -I./includes

HEADERS = libftg.h


.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: srcs/%.c
	gcc -o $@ -c $< $(FLAGS) $(INCLUDES)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
