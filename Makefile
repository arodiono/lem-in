# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arodiono <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/28 18:26:07 by arodiono          #+#    #+#              #
#    Updated: 2017/06/09 22:13:12 by arodiono         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./include/ ./libft/
LIB_PATH = ./libft/

SRC_NAME = main.c utils.c validation.c path.c combinator.c \
			traffic.c help.c printing.c reading.c
OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = -lft
NAME = lem-in
DEP = include/lem-in.h

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(addprefix -L,$(LIB_PATH))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: lib
	@echo "\033[37;44m Make $(NAME) \033[0m"
	@make $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LIB) $(LIB_NAME) $^ -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INCLUDE)
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

lib:
	@echo "\033[37;44m Make libft \033[0m"
	@make -C ./libft/

clean:
	rm -rf $(OBJ) $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)
	@make -C ./libft/ fclean

re: fclean all

.PHONY: lib clean fclean re
