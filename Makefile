# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lothieve <lothieve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/08 11:37:59 by lothieve          #+#    #+#              #
#    Updated: 2020/06/01 11:53:07 by lothieve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = mkclass.cpp

OBJS = ${SRCS:.cpp=.o}

NAME = mkclass

CFLAGS = -Wall -Wextra -Werror

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
