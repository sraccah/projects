# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/11 16:57:48 by sraccah           #+#    #+#              #
#    Updated: 2014/07/01 19:23:14 by sraccah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

MAKE = make
CC = gcc
RM = /bin/rm
SDIR = srcs/

SRC = $(SDIR)main.c \
		$(SDIR)ft_action.c \
		$(SDIR)ft_error.c \
		$(SDIR)ft_lib.c \
		$(SDIR)ft_term.c

OBJ = $(SRC:.c=.o)
INC = -I includes
LIB = -L /usr/lib -ltermcap
CFLAGS = -Wall -Wextra -Werror
R = \033[31;1m
G = \033[32;1m
Y = \033[33;1m
B = \033[34;1m
P = \033[35;1m
C = \033[36;1m
Z = \033[0m
A = $(R)[$(B)$(NAME)$(R)]----->\033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(INC) $^ -o $(NAME) $(LIB)
	@echo "$(A)$(R)[$(Y)Compilation$(R):$(G) DONE$(R)]$(Z)"
	@echo "\n$(Y)-----------------------------------"
	@echo "$(Y)--------- $(R)[$(B)$(NAME) $(G)created$(R)]$(Y) --------$(Z)"
	@echo "$(Y)-----------------------------------"
	@echo "\n$(Y)------------ $(P)Enjoy $(C);)$(Y) -------------$(Z)\n"

%.o:%.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@$(RM) -f $(OBJ)
	@echo "$(R)[$(Y)Clean$(R): $(G)DONE$(R)]$(Z)"

fclean: clean
	@$(RM) -f $(OBJ) $(NAME)
	@echo "$(R)[$(Y)Fclean$(R): $(G)DONE$(R)]$(Z)"

re: fclean all

.PHONY: all name clean fclean re