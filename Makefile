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
vpath %.c src
vpath_h = -Iinclude -Iminilibx_macos -Ilibft/includes
LIB = -Llibft/ -lft -Lminilibx_macos -lmlx

MINIFLAGS = -framework OpenGL -framework AppKit
CC = gcc 

OBJDIR := obj
OBJS := $(addprefix $(OBJDIR)/,algos.o cleaners.o main.o events.o)

$(OBJDIR)/%.o : %.c
	@$(CC) $(CPPFLAGS) $(CFLAGS) $(vpath_h) -Wall -Wextra -Werror -c \
	$(OUTPUT_OPTION) $<

all : $(OBJS)
	@make -C libft/
	@make -C minilibx_macos/
	@$(CC) $(LIB) -o $(NAME) $(OBJS) $(MINIFLAGS)

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	@mkdir $(OBJDIR)

clean :
	@make clean -C libft
	@/bin/rm -rf $(OBJDIR)
	@echo "clean fractol"
fclean : clean
	make fclean -C libft
	@/bin/rm -f $(NAME)

re: fclean all