# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 07:24:25 by Arsene            #+#    #+#              #
#    Updated: 2023/04/05 10:32:24 by arurangi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo
SRC_FOLDER	=	srcs/

COMPILER	=	gcc
FLAGS		=	-Wall -Werror -Wextra
SANITIZER	=	-g -fsanitize=address
SRC_FILES	=	$(SRC_FOLDER)/main.c \
				$(SRC_FOLDER)/errors.c \
				$(SRC_FOLDER)/checker.c \
				$(SRC_FOLDER)/display.c \



all:
	@$(COMPILER) $(FLAGS) -o $(NAME) $(SRC_FILES)