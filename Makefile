# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: corellan <corellan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 23:53:03 by corellan          #+#    #+#              #
#    Updated: 2023/07/13 01:17:07 by corellan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02

SRC = main.c ft_strlen.c ft_strdup.c ft_process_document.c ft_strjoin_free.c

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