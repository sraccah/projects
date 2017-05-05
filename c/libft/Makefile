# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/14 17:38:13 by sraccah           #+#    #+#              #
#    Updated: 2016/06/02 10:36:59 by sraccah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

MAKE = make
CC = gcc
RM = /bin/rm

SRCS = ft_strcpy \
	  ft_strlen \
	  ft_strcmp \
	  ft_strncmp \
	  ft_memmove \
      ft_memchr \
      ft_memcmp \
      ft_strcat \
      ft_strncat \
      ft_strlcat \
      ft_strchr \
      ft_strrchr \
      ft_strnstr \
      ft_atoi \
      ft_isalpha \
      ft_isdigit \
      ft_isalnum \
      ft_isascii \
      ft_isprint \
      ft_toupper \
      ft_tolower \
      ft_strstr \
      ft_memset \
      ft_memcpy \
      ft_memccpy \
      ft_strdup \
      ft_bzero \
      ft_strncpy \
      ft_memalloc \
      ft_memdel \
      ft_strnew \
      ft_strdel \
      ft_strclr \
      ft_striter \
      ft_striteri \
      ft_putchar \
      ft_putstr \
      ft_putnbr \
      ft_putendl \
      ft_putnbr_fd \
      ft_putchar_fd \
      ft_putstr_fd \
      ft_linelen \
	  ft_size_list \
	  ft_print_list \
	  ft_strsub \
	  ft_strsplit \
	  ft_strreverse \
	  ft_strequ \
	  ft_strmapi \
	  ft_strjoin \
	  ft_strmap \
	  ft_isint \
	  ft_strtrim \
	  ft_error \
	  ft_print_red \
	  ft_print_green \
	  ft_print_yellow \
	  ft_print_blue \
	  ft_print_purple \
	  ft_print_rnobs \
	  ft_print_gnobs \
	  ft_print_ynobs \
	  ft_print_bnobs \
	  ft_print_pnobs \
	  ft_hashb \
	  ft_searchnode \
	  ft_print_tree \
	  ft_cleartree \
	  ft_is \
	  ft_itoa \
	  ft_lstnew \
	  ft_lstdel \
	  ft_lstdelone \
	  ft_lstmap \
	  ft_lstiter \
	  ft_lstadd \
	  ft_new_clist \
	  ft_before_clist \
	  ft_after_clist \
	  ft_head_clist \
	  ft_tail_clist \
	  ft_del_clist \
	  ft_free_elem \
	  ft_remove_elem \
	  ft_removefirst_elem \
	  ft_removelast_elem \
	  ft_print_color \
	  ft_strnlen \
	  ft_strnequ

SRC_FILES = $(addsuffix .c,$(SRCS))
OBJS = $(SRC_FILES:.c=.o)
INC = -I includes/
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

$(NAME):
	$(CC) $(CFLAGS) -c $(SRC_FILES) $(INC)
	@echo "$(A)$(R)[$(Y)Compilation $(R): $(G)DONE$(R)] ✅$(Z)"
	ar rc $(NAME) $(OBJS)
	@echo "$(A)$(R)[$(Y)AR RC$(R): $(G)DONE$(R)] ✅$(Z)"
	ranlib $(NAME)
	@echo "$(A)$(R)[$(Y)RanLib$(R): $(G)DONE$(R)] ✅$(Z)"
	@echo "\n$(Y)-----------------------------------$(Z)"
	@echo "$(Y)------ $(R)[$(B)libft.a $(G)created$(R)] 💟 $(Y) -------$(Z)"
	@echo "$(Y)-----------------------------------$(Z)"

clean:
	$(RM) -rf $(OBJS)
	@echo "$(A)$(R)[$(Y)Cleaning $(R): $(G)DONE$(R)] ❌$(Z)"

fclean: clean
	$(RM) -rf $(NAME)
	@echo "$(A)$(R)[$(Y)Full Cleaning (clean + $(NAME))$(R): $(G)DONE$(R)] ❌$(Z)"

re: fclean all

.PHONY: all name clean fclean re