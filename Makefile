# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/26 16:57:41 by ojerroud          #+#    #+#              #
#    Updated: 2017/11/08 14:16:20 by ojerroud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = fractol.c algos.c cleaners.c events.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -o

MINIFLAGS = -L./minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

LIBFLAGS = -L./libft/ -lft

CC = gcc

INCDIR = -I minilibx_macos/ -I libft/includes

.PHONY: all re clean fclean
	
all : $(NAME)

$(NAME): comp_lib
	@$(CC) $(CFLAGS) $(NAME) $(SRC) $(INCDIR) $(MINIFLAGS) $(LIBFLAGS)
	@echo "compile done."
	
comp_lib:
	make -C libft/
	make -C minilibx_macos/

clean : 
	make clean -C libft
	/bin/rm -f $(OBJ)

fclean : clean
	make fclean -C libft
	/bin/rm -f $(NAME)

re: fclean all

