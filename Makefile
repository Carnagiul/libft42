# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: piquerue <piquerue@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/02 14:20:07 by piquerue          #+#    #+#              #
#    Updated: 2022/02/10 19:29:01 by piquerue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = project.exe
PROJECT = Project.exe

LIBFT = libft.a

CFLAGS = -Wall -Werror -Wextra -Ofast -Wunreachable-code
LIBRARIES = $(shell find . -type f | grep "\.a")
BIN = $(shell find . -type f | grep $(NAME) | wc -l | tr -d '[:space:]')
C = $(shell find ./libft -type f | grep "\.c")
C2 = $(shell find ./project -type f | grep "\.c")
BASE_PATH = $(shell pwd)

$(NAME): check display
	@if [ $(BIN) = 0 ]; then make install; fi
	@if [ $(BIN) = 1 ]; then echo "$(NAME) is compiled"; fi

#@printf "\033[1A\033[KCompiling Project \033[33m%s\033[37m\n" $(NAME)

all: $(NAME)

install:
	# @bash .sh_tool/makefiles/compile.sh
	if [ $(BIN) = 0 ]; then bash .sh_tool/grep_clang.sh; gcc -o $(NAME) $(C) main.c -g -lpthread -I Include/; else echo "Projet is compiled"; fi
	@$(eval BIN=1)

clean: display
	@bash .sh_tool/makefiles/clean.sh

fclean: clean
	@rm -f $(NAME) $(LIBFT)
	@bash .sh_tool/makefiles/fclean.sh

re: fclean all

display:
	@bash .sh_tool/display.sh $(PROJECT)

check:
	@bash .sh_tool/check.sh

git:
	@bash .sh_tool/git.sh

.PHONY : all clean fclean re $(NAME) test

#@printf "\033[1A\033[KCompiling Source \033[32m%s\033[37m =====> \033[31m%s\033[37m\n" $< $@
