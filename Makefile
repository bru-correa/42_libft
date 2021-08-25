# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/24 19:32:26 by bcorrea-          #+#    #+#              #
#    Updated: 2021/08/25 01:13:43 by bcorrea-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ = ./obj
SRC = ./src
BIN = ./bin
INCLUDE = ./include
LIB = ./lib
NAME = libft
TESTS = ./tests

CC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(NAME) tests

tests: \
	$(BIN)/tests

$(NAME): \
	$(OBJ)/isalpha.o
	ar -rcs $(LIB)/$(NAME).a $(OBJ)/*.o

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	$(CC) -c $(FLAGS) $< -I $(INCLUDE) -o $@

$(BIN)/%: $(TESTS)/%.c
	$(CC) $(FLAGS) $< $(LIB)/$(NAME).a -I $(INCLUDE) -o $@

clean:
	rm -rf $(OBJ)/*
	rm -rf $(LIB)/*

clean_tests:
	rm -rf $(BIN)/*

fclean: clean clean_tests

re: fclean all

run:
	$(BIN)/tests

.PHONY: \
	all tests clean clean_tests fclean re run
