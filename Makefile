# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnaamaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/21 17:37:18 by rnaamaou          #+#    #+#              #
#    Updated: 2021/12/21 17:37:20 by rnaamaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	=	libftprintf.a

FUNC	=	ft_printf.c

SRCS	=	utils/ft_putchar_fd.c \
			utils/ft_putnbr_base.c \
			utils/ft_putnbr_fd.c \
			utils/ft_putstr_fd.c \
			utils/ft_strlen.c\
			

OBJS	=	${SRCS:utils/%.c=%.o}

OBJS_FUN	=	${FUNC:.c=.o}

INCL	=	ft_printf.h

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror -c

all : ${NAME}

${NAME} : ${OBJS_FUN} ${OBJS} ${INCL}
	ar rcs $@ $^

${OBJS}	: ${SRCS}
	${CC} ${FLAGS} ${SRCS}

${OBJS_FUN}	: ${FUNC}
	${CC} ${FLAGS} ${FUNC}

clean :
	rm -f ${OBJS} ${OBJS_FUN}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : clean fclean all re