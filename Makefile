# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/01 17:37:06 by bcorrea-          #+#    #+#              #
#    Updated: 2021/09/01 22:07:59 by bcorrea-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
FLAGS	= -Wall -Werror -Wextra
CC		= gcc
INCLUDE	= libft.h ./tests/include/libtest.h # EDIT THIS LATER
TEST_SH	= ./tests/start_tests.sh

MAIN_S	= isalpha.c isdigit.c isalnum.c isascii.c isprint.c strlen.c memset.c \
			bzero.c memcpy.c \ memmove.c strlcpy.c strlcat.c toupper.c \
			tolower.c strchr.c strrchr.c strncmp.c memchr.c memcmp.c strnstr.c \
			atoi.c calloc.c strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
			ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
			ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

MAIN_O	= $(MAIN_S:.c=.o)
BONUS_S	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c
BONUS_O	= $(BONUS_S:.c=.o)

# REMOVE LATER
TEST_S	= $(addprefix ./tests/src/tests/, $(MAIN_S) $(BONUS_S))
TEST_O	= $(addprefix ./tests/obj/tests/, $(MAIN_O) $(BONUS_O))

all: $(NAME)

$(NAME): $(MAIN_O) $(INCLUDE)
	ar -rcs $(NAME) $(MAIN_O)

%.o: %.c
	$(CC) $(FLAGS) -c $(INCLUDE) $< -o $@

bonus: $(NAME) $(BONUS_O)
	ar -rcs $(NAME) $(BONUS_O)

clean:
	rm -f $(MAIN_O) $(BONUS_O)

fclean: clean
	rm -f $(NAME)

re: fclean all

rebonus: fclean bonus

# REMOVE LATER
test: all bonus $(TESTS_O)
	$(TEST_SH)
