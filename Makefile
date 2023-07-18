# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/18 09:46:21 by corellan          #+#    #+#              #
#    Updated: 2023/07/18 09:46:24 by corellan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02

SRC = main.c ft_strlen.c ft_strdup.c ft_process_document.c ft_strjoin_free.c \
ft_split.c ft_check_arg_number.c ft_strncmp.c ft_parse_document.c \
ft_free_split.c find_utils.c ft_find_and_print.c ft_parse_line.c ft_putstr.c \
ft_strjoin.c ft_strndup.c ft_find_recursibly.c ft_find_recursibly2.c

OBJ = $(SRC:.c=.o)

CC = cc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(FLAGS) -I. $(OBJ) -o $(NAME)

$(OBJ):
		$(CC) $(FLAGS) -I. -c $(SRC)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all