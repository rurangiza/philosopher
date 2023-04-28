# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 07:24:25 by Arsene            #+#    #+#              #
#    Updated: 2023/04/28 16:59:40 by arurangi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ~~~~~~ Variables ~~~~~~~~ #
NAME		=	philo

COMPILER	=	gcc

FLAGS		=	-Wall -Werror -Wextra $(LINK_OPTION) $(SANITIZER)
#$(SANITHREAD)
LINK_OPTION	=	-pthread
SANITIZER	=	-fsanitize=address
SANITHREAD	=	-fsanitize=thread

# ~~~~~~~~ COLOR  ~~~~~~~~~~ #
CLR_BLACK   = \033[0;30m
CLR_RED		= \033[0;31m
CLR_GREEN	= \033[0;32m
CLR_LBLUE   = \033[0;94m
CLR_YELLOW  = \033[0;33m
CLR_MAGENTA = \033[0;35m
CLR_RESET	= \033[0m

# ~~~~~~ Files and Folders ~~~~~~~~ #

SRC_FOLDER	=	./srcs/
LIB_FOLDER	=	./srcs/library/
OBJ_FOLDER	=	

SRC_FILES	=	$(SRC_FOLDER)main.c \
				$(SRC_FOLDER)errors.c \
				$(SRC_FOLDER)checker.c \
				$(SRC_FOLDER)display.c \
				$(SRC_FOLDER)init.c \
				$(SRC_FOLDER)library.c \
				$(SRC_FOLDER)linkedlist.c \
				$(SRC_FOLDER)routine.c \
				$(SRC_FOLDER)time.c \
				$(SRC_FOLDER)routine_monitored.c \

# ~~~~~~~~~ OBJECT FILES ~~~~~~~~~~~ 

OBJ_FILES	=	${SRC_FILES:.c=.o}

%.o: %.c
	$(CC) $(FLAGS)  -c $< -o $@

# ~~~~~~~~~~~~ Rules ~~~~~~~~~~~~~ #


all: 	$(NAME)
		
$(NAME):	 $(OBJ_FILES) 
				$(COMPILER) $(FLAGS) -o $(NAME) $(SRC_FILES)

clean:
				rm -f $(OBJ_FILES)		

fclean:	clean
				rm -f ${NAME}

re:		fclean all

run:
	@./$(NAME)

git:
	git add .
	git commit -m "$m"
	git push

.PHONY:	all clean fclean re git