NAME        =	RPN

SRCS 		=	 RPN.cpp \
				 main.cpp

INCLUDES	=	 RPN.hpp

OBJS        =    ${addprefix objs/, ${SRCS:.cpp=.o}}

CC          =    c++

CFLAGS      =    -Wall -Werror -Wextra -std=c++98

RM          =    rm -rf

objs/%.o:	%.cpp Makefile
	@mkdir -p $(dir $@)             
	$(CC) -g3 ${CFLAGS} -c $< -o $@

all:	${NAME}

${NAME}:	${OBJS} ${INCLUDES}        
	$(CC) ${CFLAGS} -o $(NAME) ${OBJS}

clean:
	${RM} objs/

fclean:	clean 
	${RM} ${NAME}

re:	fclean all

.PHONY:		all clean fclean re