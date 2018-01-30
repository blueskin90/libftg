# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toliver <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/12 01:24:53 by toliver           #+#    #+#              #
#    Updated: 2018/01/30 03:14:36 by toliver          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftg.a

FLAGS = -Wall -Wextra -Werror -Ofast

FILES = vector.c \
		quaternion.c \
		angle.c \

SRC = $(FILES)

SRC_PATH = srcs/

SRCS = $(addprefix $(SRC_PATH),$(SRC))

OBJS = $(SRC:.c=.o)

INCLUDES = -I./includes

HEADERS = libftg.h


.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	ar rcs $(NAME) $(OBJS)

%.o: srcs/%.c $(HEADER)
	gcc -o $@ -c $< $(FLAGS) $(INCLUDES)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

test: $(NAME)
	gcc -o test.out main.c libftg.a $(INCLUDES) $(FLAGS)
