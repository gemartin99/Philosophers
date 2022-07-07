NAME = philo

SRCS = ft_atoi.c init_values.c philosophers.c routine.c time_utils.c \
		main_checker.c ft_actions.c create_mtx_and_pth.c

INCLUDE = philosophers.h \

CC = gcc
RM = rm -f
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror -MMD 
#-g3 -fsanitize=thread

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

OBJS = ${SRCS:.c=.o}
DEPS = $(addsuffix .d, $(basename $(SRCS)))

all:	${NAME}

-include $(DEPS)
${NAME}:	${OBJS}
			$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean:
			${RM} ${OBJS} ${DEPS}

fclean: clean
			${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
