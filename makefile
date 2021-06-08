NAME	 	= push_swap

SRCS		=  stack.c check.c  sort_helper.c list_function.c main.c chunk.c

INCLUDES	=	include

OBJS		= ${SRCS:.c=.o}

LIBFT_DIR 	= libft

SRCS_LIBFT 	= ${wildcard libft/*.c}

OBJS_LIBFT	= ${SRCS_LIBFT:.c=.o}

OBJS		= ${SRCS:.c=.o}

CC			= gcc -g

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:
				${CC} ${CFLAGS} -c -I ${INCLUDES} $< -o ${<:.c=.o} 


all: 			${NAME}

${NAME}:	$(OBJS) 
			@make -C $(LIBFT_DIR)
			@$(CC) $(CFLAGS) -I $(INCLUDES) $(OBJS)  -Llibft -lft -o $(NAME)


clean:
				${RM} ${OBJS} 
				${RM} ${OBJS_LIBFT} 

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re