# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/10 11:54:19 by leramos-          #+#    #+#              #
#    Updated: 2025/06/24 12:57:02 by leramos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = libftprintf.a

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

# Project structure
SRCS_DIR = .
LIBFT_DIR = libft

# Files
FILES = main input utils op_swap op_push op_rotate op_reverse_rotate sorting sorting_utils chunk_utils sorted_stack quicksort
LIBFT_LIB = $(LIBFT_DIR)/libft.a
OUT_FILE = push_swap.exe

SRCS = $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(FILES)))
OBJS = $(SRCS:.c=.o)

# Rules
all: ${NAME}

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

# Compile all push_swap .c to .o
# Compile libft to static library (.a) (?)
# Link all .o files and libft.a into push_swap.out
${NAME}: ${OBJS} $(LIBFT_LIB)
	$(CC) $(CFLAGS) $^ -o $(OUT_FILE)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

# Phony targets
.PHONY: all bonus clean fclean re