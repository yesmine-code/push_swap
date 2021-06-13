NAME	 	= push_swap

SRCS		=  stack.c check.c  sort_helper.c sort_helper2.c list_function.c list_function2.c main.c chunk.c lib.c lib2.c

INCLUDES	=	include

OBJS		= ${SRCS:.c=.o}

OBJS		= ${SRCS:.c=.o}

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:
				${CC} ${CFLAGS} -c -I ${INCLUDES} $< -o ${<:.c=.o} 


all: 			${NAME}

${NAME}:	$(OBJS) 
			@$(CC) $(CFLAGS) -I $(INCLUDES) $(OBJS) -o $(NAME)


clean:
				${RM} ${OBJS} 

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re