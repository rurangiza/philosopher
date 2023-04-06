# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 07:24:25 by Arsene            #+#    #+#              #
#    Updated: 2023/04/06 10:50:53 by arurangi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ~~~~~~ Files and Folders ~~~~~~~~ #
NAME		=	philo
SRC_FOLDER	=	srcs/

SRC_FILES	=	$(SRC_FOLDER)/main.c \
				$(SRC_FOLDER)/errors.c \
				$(SRC_FOLDER)/checker.c \
				$(SRC_FOLDER)/display.c \

COMPILER	=	gcc

FLAGS		=	-Wall -Werror -Wextra $(LINK_OPTION)
SANITIZER	=	-g -fsanitize=address
LINK_OPTION	=	-pthread	



# ~~~~~~~~~~~~ Rules ~~~~~~~~~~~~~ #
all:
	@$(COMPILER) $(FLAGS) -o $(NAME) $(SRC_FILES)