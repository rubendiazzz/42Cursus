# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makef ile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdiaz-fr <rdiaz-fr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 12:31:04 by rdiaz-fr          #+#    #+#              #
#    Updated: 2023/09/17 15:15:35 by rdiaz-fr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Lista de archivos fuente (.c) que se compilarán
SRCS			= ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
				  ft_isdigit.c ft_isprint.c ft_memcpy.c ft_memmove.c \
				  ft_memset.c ft_strlcpy.c ft_strlen.c ft_strlcat.c \
				  ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
				  ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
				  ft_atoi.c is_negative.c ft_calloc.c ft_strdup.c \
				  ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
				  ft_itoa.c

# Lista de archivos objeto (.o) que se generarán a partir de los archivos fuente
OBJS			= $(SRCS:.c=.o)

# Archivos de cabecera utilizados en el proyecto
HEADERS			= libft.h

# Compilador de C a utilizar (en este caso, GCC)
CC				= gcc

# Comando para eliminar archivos
RM				= rm -f

# Flags del compilador; -Wall, -Wextra y -Werror habilitan advertencias, -I. especifica buscar en el directorio actual los archivos de inclusión
CFLAGS			= -Wall -Wextra -Werror -I.

# Nombre del archivo de biblioteca (.a) que se creará
NAME			= libft.a

# Objetivo por defecto; si ejecutamos 'make' sin argumentos, se ejecutará este objetivo que depende de $(NAME)
all:			$(NAME)

# Especifica cómo crear el archivo de biblioteca; depende de todos los archivos objeto listados en OBJS
$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

# Indica que todos los archivos objeto dependen de los archivos de cabecera
$(OBJS):		$(HEADERS)

# Regla patrón que indica cómo crear un archivo .o a partir de un archivo .c
.c.o:
				$(CC) $(CFLAGS) -c $< -o $@

# Elimina todos los archivos objeto
clean:
				$(RM) $(OBJS)

# Elimina tanto los archivos objeto como el archivo de biblioteca
fclean:			clean
				$(RM) $(NAME)

# Limpia todo con fclean y luego reconstruye el proyecto
re:				fclean $(NAME)

# Especifica que estos son objetivos ficticios, es decir, no producen un archivo con el nombre del objetivo
.PHONY:			all clean fclean re
