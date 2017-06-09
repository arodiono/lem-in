# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arodiono <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/21 14:49:52 by arodiono          #+#    #+#              #
#    Updated: 2016/12/08 15:18:12 by arodiono         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Werror -Wextra
SRC = ft_atoi.c ft_lstadd.c ft_memcpy.c ft_putstr.c ft_striter.c ft_strnequ.c \
		ft_bzero.c ft_lstdel.c ft_memdel.c ft_putstr_fd.c ft_striteri.c \
		ft_strnew.c ft_isalnum.c ft_lstdelone.c ft_memmove.c ft_strcat.c \
		ft_strjoin.c ft_strnstr.c ft_isalpha.c ft_lstiter.c ft_memset.c \
		ft_strchr.c ft_strlcat.c ft_strrchr.c ft_isascii.c ft_lstmap.c \
		ft_putchar.c ft_strclr.c ft_strlen.c ft_strsplit.c ft_isblank.c \
		ft_lstnew.c ft_putchar_fd.c ft_strcmp.c ft_strmap.c ft_strstr.c \
		ft_isdigit.c ft_memalloc.c ft_putendl.c ft_strcpy.c ft_strmapi.c \
		ft_strsub.c ft_isprint.c ft_memccpy.c ft_putendl_fd.c ft_strdel.c \
		ft_strncat.c ft_strtrim.c ft_isxdigit.c ft_memchr.c ft_putnbr.c \
		ft_strdup.c ft_strncmp.c ft_tolower.c ft_itoa.c ft_memcmp.c \
		ft_putnbr_fd.c ft_strequ.c ft_strncpy.c ft_toupper.c ft_strupcase.c \
		ft_strlowcase.c get_next_line.c

OSRC =	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OSRC)
	gcc $(FLAGS) -c $(SRC)
	ar rc libft.a $(OSRC)

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	rm -f $(OSRC)

fclean: clean
	rm -f libft.a

re: all
