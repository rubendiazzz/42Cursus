# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 16:42:19 by rdiaz-fr          #+#    #+#              #
#    Updated: 2023/10/10 16:51:24 by rdiaz-fr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Color codes
RED=\033[0;31m
GREEN=\033[0;32m
NC=\033[0m # No Color

# Source and object files
SRCS	=	src/ft_printf.c src/handle_format.c src/handle_string.c src/count_digits.c \
			src/handle_char.c src/handle_hex.c src/handle_integer.c src/handle_pointer.c \
			src/handle_unsigned.c src/count_hex_digits.c src/ft_putnbr_base.c src/check_base.c \

OBJS	=	$(SRCS:.c=.o)

# Compiler and flags
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -Iincludes -Ilibft

# Project name
NAME	= libftprintf.a

# Dependency libraries
LIBFT	= libft/libft.a

# Main targets
all: $(LIBFT) $(NAME)

# To prevent relinking, specify the dependency between object files and source files
%.o: %.c
	@echo "$(GREEN)Compiling $<$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C libft

$(NAME): $(OBJS)
	@echo "$(GREEN)Creating Archive $(NAME)$(NC)"
	@ar -x $(LIBFT)
	@ar -rcs $(NAME) $(OBJS) *.o
	@rm *.o

clean:
	@echo "$(RED)Removing Object Files$(NC)"
	@$(RM) $(OBJS)
	@make -C libft clean

fclean: clean
	@echo "$(RED)Removing Library $(NAME)$(NC)"
	@$(RM) $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
