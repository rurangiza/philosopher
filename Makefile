# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 07:24:25 by Arsene            #+#    #+#              #
#    Updated: 2023/04/04 08:25:59 by Arsene           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo
COMPILER	=	gcc
FLAGS		=	-Wall -Werror -Wextra
SANITIZER	=	-g -fsanitize=address
SRC_FILES	=	main.c \
				errors.c \
				checker.c \



all:
	@$(COMPILER) $(FLAGS) -o $(NAME) $(SRC_FILES)