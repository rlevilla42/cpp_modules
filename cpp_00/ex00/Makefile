# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlevilla <rlevilla42@student.42lausanne.c  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 18:28:52 by rlevilla          #+#    #+#              #
#    Updated: 2024/02/15 23:08:51 by rlevilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	megaphone.cpp

CC = g++

//LEAKS = leaks -atExit --

CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = megaphone

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

.c .o:
		$(CC) -c $< -o $(<:.c=.o)

RM = rm -f

${NAME}:	${OBJ}
			${CC} ${CFLAGS} ${OBJ} -o ${NAME}

clean:	
		$(RM) $(OBJ) $(NAME)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all
