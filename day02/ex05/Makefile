NAME		=	Karen2.0Filter


SRCS		=	main.cpp Karen.cpp

OBJS		=	${SRCS:.cpp=.o} 

CC			=	clang++

CFLAGS		=	-Wall -Wextra -Werror -std=c++98

RM			=	rm -f

all:			${NAME}

%.o: %.cpp
				${CC} ${CFLAGS} -c -o $@ $^

$(NAME):		${OBJS}
				${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
				${RM}  ${OBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all