# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvlassen <dvlassen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/21 17:51:54 by dvlassen          #+#    #+#              #
#    Updated: 2020/07/21 17:55:43 by dvlassen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = ./*.c
OBJ = $(SRC:.c=.o)
HEADER = fillit.h
LIBFT = libft/
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C $(LIBFT)
	gcc $(FLAGS) -c $(SRC)
	gcc $(OBJ) libft/libft.a $(FLAGS) -o $(NAME)

clean:
		rm -f $(OBJ)
		make clean -C libft/

fclean: clean
		rm -f $(NAME)
		make fclean -C libft/
		
re: fclean all
