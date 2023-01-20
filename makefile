NAME 		=	push_swap

# NAME_BONUS	= 	push_swap_bonus

SRC = 			./src/main.c \
	  			./src/sort.c \
	  			./src/stack_build.c \
				./src/stack_operations.c

# SRC_BONUS	= 	./bonus/src/childs_bonus.c \
# 	  			./bonus/src/pipex_bonus.c \
# 	  			./bonus/src/split_bonus.c \
# 	  			./bonus/src/utils_bonus.c

INC			=	-I ./inc \
				# -I./bonus/inc

OBJS		=	${SRC:.c=.o}

# OBJS_BONUS	= 	${SRC_BONUS:.c=.o}

CC			=	gcc

CFLAG		=	-Wall -Werror -Wextra -g

${NAME}: 		${OBJS} 
				${CC} ${CFLAG} ${OBJS} -o ${NAME}

# ${NAME_BONUS}: 	${OBJS_BONUS} 
# ${CC} ${CFLAG} ${OBJS_BONUS} -o ${NAME_BONUS}		

all: 			${NAME}

# bonus: 			${NAME_BONUS}	

.c.o:
				${CC} ${CFLAG} ${INC} -c $< -o ${<:.c=.o}

clean:
				rm -f ${OBJS}
# rm -f ${OBJS_BONUS}

fclean: 		clean
				rm -f ${NAME} 
# rm -f ${NAME_BONUS} 

re: 			fclean all

.PHONY: 		all clean fclean re #bonus