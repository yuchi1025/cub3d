# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/03 10:21:25 by yucchen           #+#    #+#              #
#    Updated: 2026/02/18 12:51:57 by yucchen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and parameters
CC = cc
CFLAGS = -Wall -Wextra -Werror -I/usr/include
MLX_FLAGS = -Lminilibx-linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz
MAKE = make

# File name and file list
NAME = cub3D
SOURCES = file_check.c \
		  init_mlx.c   \
		  raycaster.c  \
		  main.c
OBJECTS = $(SOURCES:.c=.o)

LIBFT_DIR = libft
LIBFT_AR = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX_AR = $(MLX_DIR)/libmlx.a

# Compile mandatory part
all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT_AR) $(MLX_AR)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_AR) $(MLX_AR) $(MLX_FLAGS) -o $(NAME)

$(LIBFT_AR):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_AR):
	$(MAKE) -C $(MLX_DIR)

# Clean object files
clean: 
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJECTS)

# Clean object files and lib
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

# Recompile everything
re: fclean all

.PHONY: all clean fclean re
