# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: piquerue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/02 14:20:07 by piquerue          #+#    #+#              #
#    Updated: 2017/08/24 00:32:20 by piquerue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = $(shell find . -type f | grep "\.c")

OBJ= $(SRC:.c=.o)

OBJ_22 = $(subst ./src/, , $(OBJ))
OBJ_2 = $(addprefix obj/, $(OBJ_22))

INCLUDE = $(shell find ../ -type f | grep "\.h")
CFLAGS  = -Wall -Werror -Wextra
CFLAGS_2 = -Werror=pointer-to-int-cast

obj/%.o: src/%.c $(INCLUDE)
	@mkdir -p obj/
	@gcc -o $@ -c $< $(CFLAGS)
	@echo "\033[1A\033[K\033[38;5;92mcompiling $@\033[0m"

$(NAME): $(OBJ_2)
	@gcc -c $(CLAGS) $(SRC) -I ./include
	@ar rc $(NAME) $(OBJ_2)
	@mv $(OBJ_22) obj/
	@ranlib $(NAME)
	@echo "\033[38;5;154mcompiling $(NAME) done\033[0m\n"

all: $(NAME)

clean:
	@rm -f $(OBJ_2)
fclean: clean
	@rm -f $(NAME)

re: fclean all

test:
	@echo "$(OBJ_2)" 

.PHONY : all clean fclean re
