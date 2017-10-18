# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/04 14:32:18 by cbarbier          #+#    #+#              #
#    Updated: 2017/10/18 08:43:15 by cbarbier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= wolf3d
LIB				= libft/libft.a
LIBMLX			= minilibx_macos/libmlx.a
MLX				= -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit
CC				= gcc
CFLAGS				= -Wall -Wextra -Werror
HDR				= includes/wolf3d.h
SRCS 			= srcs/main.c \
				srcs/load_map.c \
				srcs/raycasting.c \
				srcs/coloring.c \
				srcs/radar.c \
				srcs/sprint.c \
				srcs/handlers.c \
				srcs/manage_event.c \
				srcs/fr33.c \
				srcs/debug.c \
				srcs/f_event1.c \
				srcs/f_event2.c \
				srcs/w3d_core.c \
				srcs/mlx.c

OBJS			= $(SRCS:.c=.o)

all: $(NAME)
	@echo " / \   / \   / \   / \   / \   / \   / \ "
	@echo "( w ) ( o ) ( l ) ( f ) ( - ) ( 3 ) ( D )"
	@echo " \_/   \_/   \_/   \_/   \_/   \_/   \_/ "

%.o:%.c $(HDR)
	@$(CC) $(CFLAGS) -c $< -o $@ -Iincludes

$(NAME): $(LIBMLX) $(LIB) $(OBJS) $(HDR)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -Llibft -lft $(MLX) 
	@echo "WOLF3D BUILT\t\t\033[0;32m✓\033[0m"

ifneq ($(shell make -q -C libft;echo $$?), 0)
.PHONY: $(LIB)
endif

$(LIB):
	@make -C libft

$(LIBMLX):
	@make -C minilibx_macos
	@echo "MINILIBX BUILT\t\t\033[0;32m✓\033[0m"

clean:
	@/bin/rm -rf $(OBJS)
	@/bin/rm -rf $(NAME).dSYM
	@make -C libft clean
	@make -C minilibx_macos clean

fclean: clean
	@/bin/rm -rf $(LIBMLX)
	@/bin/rm -rf $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: clean fclean all re
