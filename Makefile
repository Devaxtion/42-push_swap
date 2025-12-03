# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/10 11:54:19 by leramos-          #+#    #+#              #
#    Updated: 2025/12/03 15:35:40 by leramos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project structure
NAME = push_swap
SRCS_DIR = src
INCS_DIR = includes

# Libft structure
LIBFT_DIR = libft
LIBFT_SRCS_DIR = $(LIBFT_DIR)/src
LIBFT_INCS_DIR = $(LIBFT_DIR)/includes

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCS_DIR) -I$(LIBFT_INCS_DIR)
AR = ar rcs
RM = rm -f

# Files
FILES = main exit initialization validation array_utils quicksort \
		operations/op_utils operations/swap operations/push \
		operations/rotate operations/reverse_rotate \
		sorting/sorting sorting/sort_utils sorting/chunk_utils sorting/chunk_management
LIBFT_LIB = $(LIBFT_DIR)/libft.a

SRCS = $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(FILES)))
OBJS = $(SRCS:.c=.o)

# Rules
all: ${NAME}

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

${NAME}: ${OBJS} $(LIBFT_LIB)
	$(CC) $(CFLAGS) $^ -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)
	$(RM) $(NAME)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

# Phony targets
.PHONY: all bonus clean fclean re