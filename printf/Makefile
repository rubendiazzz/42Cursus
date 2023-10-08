# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/04 12:11:41 by rdiaz-fr          #+#    #+#              #
#    Updated: 2023/10/05 12:57:12 by rdiaz-fr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= src/ft_printf.c src/handle_format.c src/handle_string.c \
	  src/count_digits.c src/handle_char.c src/handle_hex.c \
	  src/handle_integer.c src/handle_pointer.c src/handle_unsigned.c \
	  src/count_hex_digits.c

OBJS	= $(SRCS:.c=.o)

CC	= gcc
RM	= rm -f
CFLAGS	= -Wall -Wextra -Werror -Iincludes -Ilibft

NAME	= libftprintf.a

LIBFT	= libft/libft.a

all:	$(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
	make -C libft clean

fclean:	clean
	$(RM) $(NAME)
	make -C libft fclean

re:	fclean all

.PHONY:	all clean fclean re
