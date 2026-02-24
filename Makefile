# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/03 10:21:25 by yucchen           #+#    #+#              #
#    Updated: 2026/02/24 14:12:55 by yucchen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and parameters
CC = cc
CFLAGS = -Wall -Wextra -Werror -I/usr/include
MLX_FLAGS = -Lminilibx-linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz
MAKE = make

# File name
NAME = cub3D
NAME_BONUS = cub3D_bonus

# Mandatory Sources (NO minimap, NO bonus files)
SOURCES = file_check.c  \
		  init_mlx.c    \
		  render.c		\
		  texture.c		\
		  move_player.c \
		  raycaster.c   \
		  main.c
OBJECTS = $(SOURCES:.c=.o)

# Bonus Sources (Use the _bonus files and include minimap.c)
BONUS_SOURCES = file_check.c     \
		  		init_mlx_bonus.c \
		  		render_bonus.c	 \
		  		texture.c	     \
		  		move_player.c    \
		  		raycaster.c      \
		  		minimap.c	     \
		  		main.c
BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

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

# Compile bonus part
bonus: $(NAME_BONUS)

$(NAME_BONUS): $(BONUS_OBJECTS) $(LIBFT_AR) $(MLX_AR)
	$(CC) $(CFLAGS) $(BONUS_OBJECTS) $(LIBFT_AR) $(MLX_AR) $(MLX_FLAGS) -o $(NAME_BONUS)

# Clean object files
clean: 
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJECTS) $(BONUS_OBJECTS)

# Clean object files and lib
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME) $(NAME_BONUS)

# Recompile everything
re: fclean all

.PHONY: all bonus clean fclean re 
