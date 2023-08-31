NAME        =	RPN

SRCS 		=	 $(shell find -name '*.cpp')

OBJS        =    ${addprefix objs/, ${SRCS:.cpp=.o}}

CC          =    c++

CFLAGS      =    -Wall -Werror -Wextra -Wno-unused -std=c++98

RM          =    rm -rf

objs/%.o:	%.cpp Makefile
	@mkdir -p $(dir $@)             
	$(CC) -g3 ${CFLAGS} -c $< -o $@

all:	${NAME}

${NAME}:	${OBJS}           
	$(CC) -g3 ${CFLAGS} -o $(NAME) ${OBJS}

clean:
	${RM} objs/

fclean:	clean 
	${RM} ${NAME}

re:	fclean all

.PHONY:		all clean fclean re