# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 07:55:41 by hbourgeo          #+#    #+#              #
#    Updated: 2022/03/31 16:34:46 by hbourgeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = pipex
DEPS = pipex.h

SRC = pipex.c \
		error_handling.c \
		utils.c	\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(SRC) $(DEPS)
	make -C libft
	$(CC) $(CFLAGS) $(SRC) libft/libft.a -o $@

clean :
	rm -rf $(NAME) $(OBJ)

fclean : clean
	make fclean -C libft

re : fclean all

.PHONY : clean fclean all re