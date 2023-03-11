NAME 		=	push_swap

SRC = 			./src/error_free_exit.c \
				./src/main.c \
	  			./src/sort.c \
	  			./src/pushes_swapses.c \
	  			./src/rotations.c \
	  			./src/stack_progress.c \
	  			./src/stack_build.c \
				./src/stack_operations.c

INC			=	-I ./inc

OBJS		=	${SRC:.c=.o}

CC			=	gcc

CFLAG		=	-Wall -Werror -Wextra -g

${NAME}: 		${OBJS} 
				${CC} ${CFLAG} ${OBJS} -o ${NAME}

all: 			${NAME}

.c.o:
				${CC} ${CFLAG} ${INC} -c $< -o ${<:.c=.o}

clean:
				rm -f ${OBJS}

fclean: 		clean
				rm -f ${NAME} 

re: 			fclean all

.PHONY: 		all clean fclean re