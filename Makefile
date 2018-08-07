# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: piquerue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/02 14:20:07 by piquerue          #+#    #+#              #
#    Updated: 2018/08/07 07:32:46 by piquerue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra -Ofast -Wunreachable-code
LIBFT = libft
C = $(shell find . -type f | grep "\.c")
COUNT = $(shell find . -type f | grep "\.o" | wc -l | tr -d '[:space:]')
COUNT_MAX = $(shell find . -type f | grep "\.c" | wc -l | tr -d '[:space:]')
H = $(shell find . -type f | grep "\.h")
O = $(C:%.c=%.o)
T = 0
MODIFS_C = $(shell find . | grep "libft42.a" | wc -l | tr -d '[:space:]')
BIN = $(shell find . | grep $(NAME) | wc -l | tr -d '[:space:]')


%.o: %.c $(H)
	@if [ $(BIN) = 1 ]; then rm -rf $(NAME); fi
	$(eval BIN=0)
	@gcc $(CFLAGS) -I Include/ -o $@ -c $< &
	$(call plus,$(COUNT), 1)
	$(eval MODIFS_C=$(COUNT))
	@printf "Compiling Source \033[32m%d\033[37m / \033[31m%d\033[37m\n" $(COUNT) $(COUNT_MAX)

$(NAME): check display $(O)
	@if [ $(MODIFS_C) > 0 ]; then make install; fi
	@if [ $(BIN) = 0 ]; then make install; fi
	@if [ $(BIN) = 1 ]; then echo "$(NAME) is compiled"; fi

#@printf "\033[1A\033[KCompiling Project \033[33m%s\033[37m\n" $(NAME)

all: $(NAME)

install:
	@if [ $(BIN) = 0 ]; then sh .sh_tool/grep_clang.sh; ar rc $(NAME) $(O); ranlib $(NAME); else echo "Projet is compiled"; fi
	@$(eval BIN=1)

clean: display
	@rm -rf $(O)
fclean: clean
	@rm -f $(NAME)

re: fclean all

display:
	@sh .sh_tool/display.sh

check:
	@sh .sh_tool/check.sh

.PHONY : all clean fclean re $(NAME)

#@printf "\033[1A\033[KCompiling Source \033[32m%s\033[37m =====> \033[31m%s\033[37m\n" $< $@
