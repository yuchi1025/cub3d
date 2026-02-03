# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/07 14:09:48 by yucchen           #+#    #+#              #
#    Updated: 2026/01/11 18:40:55 by yucchen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and parameters
CC = cc
CFLAGS = -Wall -Wextra -Werror

# File name and file list
NAME = libft.a
SOURCES = ft_isalpha.c \
		  ft_isdigit.c \
		  ft_isalnum.c \
		  ft_isascii.c \
		  ft_isprint.c \
		  ft_strlen.c \
		  ft_memset.c \
		  ft_bzero.c \
		  ft_memcpy.c \
		  ft_memmove.c \
		  ft_strlcpy.c \
		  ft_strlcat.c \
		  ft_toupper.c \
		  ft_tolower.c \
		  ft_strchr.c \
		  ft_strrchr.c \
		  ft_strncmp.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_strnstr.c \
		  ft_atoi.c \
		  ft_calloc.c \
		  ft_strdup.c \
		  ft_substr.c \
		  ft_strjoin.c \
		  ft_strtrim.c \
		  ft_split.c \
		  ft_itoa.c \
		  ft_strmapi.c \
		  ft_striteri.c \
		  ft_putchar_fd.c \
		  ft_putstr_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c \
		  ft_printf.c \
		  ft_printf_utils.c \
		  get_next_line.c
OBJECTS = $(SOURCES:.c=.o)

BONUS_SOURCES = ft_lstnew_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstsize_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstmap_bonus.c
BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

# Compile mandatory part
all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

# Compile mandatory + bonus part
bonus: $(OBJECTS) $(BONUS_OBJECTS)
	ar rcs $(NAME) $(OBJECTS) $(BONUS_OBJECTS)

# Clean object files
clean: 
	rm -f $(OBJECTS) $(BONUS_OBJECTS)

# Clean object files and lib
fclean: clean
	rm -f $(NAME)

# Recompile everything
re: fclean all

.PHONY: all clean fclean re bonus