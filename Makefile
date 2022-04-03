# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 07:55:41 by hbourgeo          #+#    #+#              #
#    Updated: 2022/04/03 14:02:23 by hbourgeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = pipex
DEPS = pipex.h

SRC = pipex.c \
		error_handling.c \
		utils.c	\

SRC_B = pipex_bonus.c \
		error_handling.c \
		utils.c	\

all: $(NAME)

$(NAME) : $(SRC) $(DEPS)
	make -C libft
	$(CC) $(CFLAGS) $(SRC) libft/libft.a -o $@

clean :
	rm -rf $(NAME)
	make clean -C libft

fclean : clean
	make fclean -C libft

re : fclean all

bonus: $(SRC_B) $(DEPS)
	make -C libft
	$(CC) $(CFLAGS) $(SRC_B) libft/libft.a -o $(NAME)

.PHONY : clean fclean all re