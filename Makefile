PREFIXE		= ./srcs/

SRCS		= $(addprefix ${PREFIXE}, ft_putstr.c ft_swap.c ft_putchar.c ft_strlen.c ft_strcmp.c)

OBJS		= ${SRCS:.c=.o}

INCLUDES	= includes/

NAME		= libft.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -I ${INCLUDES}

RM			= rm -f

AR			= ar rc

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}

all:		${NAME}

clean: 
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

