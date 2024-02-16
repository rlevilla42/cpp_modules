# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlevilla <rlevilla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 18:28:52 by rlevilla          #+#    #+#              #
#    Updated: 2024/02/16 20:26:40 by rlevilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	main.cpp

CC = g++

//LEAKS = leaks -atExit --

CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = ROAR

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
