# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/04 14:32:18 by cbarbier          #+#    #+#              #
#    Updated: 2017/07/20 15:19:08 by cbarbier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= wolf3d
LIB				= libft/libft.a
LIBMLX			= minilibx_macos/libmlx.a
MLX				= -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit
CC				= gcc
CFLAGS				= -Wall -Wextra -Werror
HDR				= includes/wolf3d.h
SRCS				= srcs/main.c \


OBJS			= $(SRCS:.c=.o)

all: $(NAME)
	@echo " / \   / \   / \   / \   / \   / \   / \ "
	@echo "( w ) ( o ) ( l ) ( f ) ( - ) ( 3 ) ( D )"
	@echo " \_/   \_/   \_/   \_/   \_/   \_/   \_/ "

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@ -Iincludes

$(NAME): $(LIBMLX) $(LIB) $(OBJS) $(HDR)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -Llibft -lft $(MLX) 
	@echo "WOLF3D BUILT\t\t\033[0;32m✓\033[0m"

$(LIB):
	@make -C libft

$(LIBMLX):
	@make -C minilibx_macos
	@echo "MINILIBX BUILT\t\t\033[0;32m✓\033[0m"

clean:
	@/bin/rm -rf $(OBJS)
	@make -C libft clean
	@make -C minilibx_macos clean

fclean: clean
	@/bin/rm -rf $(LIBMLX)
	@/bin/rm -rf $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: clean fclean all re
