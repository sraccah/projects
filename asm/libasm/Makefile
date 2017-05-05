# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/14 17:38:13 by sraccah           #+#    #+#              #
#    Updated: 2016/03/22 13:36:34 by sraccah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libfts.a

MAKE = make
CC = clang
NASM = nasm
LK = ld
RM = /bin/rm

SRC = ft_bzero.s \
		ft_isalpha.s \
		ft_isdigit.s \
		ft_isascii.s \
		ft_isprint.s \
		ft_isalnum.s \
		ft_toupper.s \
		ft_tolower.s \
		ft_puts.s \
		ft_strlen.s \
		ft_memcpy.s \
		ft_memset.s \
		ft_strdup.s \
		ft_strnew.s \
		ft_putchar.s
OBJ = ft_bzero.o \
		ft_isalpha.o \
		ft_isdigit.o \
		ft_isascii.o \
		ft_isprint.o \
		ft_isalnum.o \
		ft_toupper.o \
		ft_tolower.o \
		ft_puts.o \
		ft_strlen.o \
		ft_memcpy.o \
		ft_memset.o \
		ft_strdup.o \
		ft_strnew.o \
		ft_putchar.o

MAIN = main.c
MAINO = main.o

NFLAGS = -f macho64
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
		 @echo "$(A)$(R)[$(Y)Compilation (nasm)$(R): $(G)DONE$(R)] ✅$(Z)"
		 @ar rc $(NAME) $(OBJ)
		 @echo "$(A)$(R)[$(Y)AR RC (ld)$(R): $(G)DONE$(R)] ✅$(Z)"
		 @ranlib $(NAME)
		 @echo "$(A)$(R)[$(Y)Ranlib (ld)$(R): $(G)DONE$(R)] ✅$(Z)"
		 @echo "\n$(Y)-------------------------------------$(Z)"
		 @echo "$(Y)-------- $(R)[$(B)$(NAME) $(G)created$(R)] 💟$(Y) -------$(Z)"
		 @echo "$(Y)-------------------------------------$(Z)"

$(OBJ):	$(SRC)
		@$(NASM) $(NFLAGS) ft_bzero.s
		@$(NASM) $(NFLAGS) ft_isalpha.s
		@$(NASM) $(NFLAGS) ft_isdigit.s
		@$(NASM) $(NFLAGS) ft_isascii.s
		@$(NASM) $(NFLAGS) ft_isprint.s
		@$(NASM) $(NFLAGS) ft_isalnum.s
		@$(NASM) $(NFLAGS) ft_toupper.s
		@$(NASM) $(NFLAGS) ft_tolower.s
		@$(NASM) $(NFLAGS) ft_puts.s
		@$(NASM) $(NFLAGS) ft_strlen.s
		@$(NASM) $(NFLAGS) ft_memcpy.s
		@$(NASM) $(NFLAGS) ft_memset.s
		@$(NASM) $(NFLAGS) ft_strdup.s
		@$(NASM) $(NFLAGS) ft_strnew.s
		@$(NASM) $(NFLAGS) ft_putchar.s

clean:
	@$(RM) -rf $(MAINO) $(OBJ)
	@echo "$(A)$(R)[$(Y)Cleaning ($(MAINO) + $(OBJ))$(R): $(G)DONE$(R)] ❌$(Z)"

fclean: clean
	@$(RM) -rf $(NAME)
	@echo "$(A)$(R)[$(Y)Full Cleaning (clean + $(NAME))$(R): $(G)DONE$(R)] ❌$(Z)"

re: fclean all

.PHONY: all name clean fclean re