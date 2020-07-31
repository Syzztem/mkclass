# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lothieve <lothieve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/08 11:37:59 by lothieve          #+#    #+#              #
#    Updated: 2020/07/28 14:29:20 by lothieve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = mkclass.cpp shellmode.cpp Variable.cpp Function.cpp Class.cpp

OBJS = ${SRCS:.cpp=.o}

NAME = mkclass

CFLAGS = -Wall -Wextra -Werror -std=c++11

CC = clang++

RM = rm -f

all:		${NAME}

.cpp.o:
			${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

${NAME}:	${OBJS}
				${CC} -o ${NAME} ${OBJS}

clean:
				${RM} ${OBJS}

fclean:		clean
				${RM} ${NAME}

re:			fclean all

install:	${NAME}
			rm -rf ~/.mkclass ; mkdir ~/.mkclass ; cp mkclass ~/.mkclass ; echo 'alias mkclass="~/.mkclass/mkclass"' >> ~/.zshrc

update:		${NAME}
			cp mkclass ~/.mkclass 

.PHONY:		all clean fclean re install update
