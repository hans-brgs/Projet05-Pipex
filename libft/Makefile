# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/30 19:37:13 by hbourgeo          #+#    #+#              #
#    Updated: 2022/02/17 17:54:07 by hbourgeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc 
CFLAGS = -Wall -Werror -Wextra 
NAME = libft.a

SRC = 	ft_isalpha.c	\
		ft_isalnum.c	\
		ft_isdigit.c	\
		ft_isascii.c	\
		ft_isprint.c 	\
		ft_strlen.c 	\
		ft_memset.c		\
		ft_bzero.c		\
		ft_memcpy.c		\
		ft_memmove.c	\
		ft_strlcpy.c	\
		ft_strlcat.c	\
		ft_toupper.c	\
		ft_tolower.c	\
		ft_strchr.c		\
		ft_strrchr.c	\
		ft_strncmp.c	\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_strnstr.c	\
		ft_atoi.c		\
		ft_calloc.c		\
		ft_strdup.c		\
		ft_substr.c		\
		ft_strjoin.c	\
		ft_strtrim.c	\
		ft_split.c		\
		ft_itoa.c		\
		ft_strmapi.c	\
		ft_striteri.c	\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c	\

OWN = 	ft_putnbr_base_fd.c 	\
		ft_putnbr_unsigned_fd.c \

SRC_B = ft_lstnew.c			\
		ft_lstadd_front.c	\
		ft_lstsize.c		\
		ft_lstlast.c		\
		ft_lstadd_back.c	\
		ft_lstdelone.c		\
		ft_lstclear.c		\
		ft_lstiter.c		\
		ft_lstmap.c			\
		
OBJ = $(SRC:.c=.o) $(OWN:.c=.o) 
OBJ_B = $(SRC_B:.c=.o)

%.o : %.c
	$(CC) -c $(CFLAGS) $^ -o $@
	
all : 	$(NAME)	

$(NAME) : $(OBJ)
	@ar -rcs $(NAME) $(OBJ)
	
bonus: $(OBJ) $(OBJ_B)
	@ar -rcs $(NAME) $(OBJ) $(OBJ_B)	

clean : 
	rm -rf $(OBJ) $(OBJ_B)
	rm -f bonus

fclean : clean
	rm -rf $(NAME)	

re : fclean all

.PHONY: clean fclean all re
