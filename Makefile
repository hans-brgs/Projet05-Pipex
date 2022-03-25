# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 07:55:41 by hbourgeo          #+#    #+#              #
#    Updated: 2022/03/24 17:03:49 by hbourgeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libftpipex.a

SRC =
		

OBJ = $(SRC:.c=.o)

%.o : %.c $(DEPS)
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(NAME)
	
$(NAME) : $(OBJ)
	make -C libft
	cp libft/libft.a $(NAME)
	ar rs $(NAME) $(OBJ)

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)
	make fclean -C libft

re : fclean all

.PHONY : clean fclean all re