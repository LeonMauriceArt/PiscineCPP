NAME        =	btc

SRCS 		=	 ./srcs/BitcoinExchange.cpp \
				 ./srcs/Date.cpp \
				 ./srcs/Exceptions.cpp \
				 main.cpp

INCLUDES	=	 ./includes/BitcoinExchange.hpp \
				 ./includes/Date.hpp \
				 ./includes/Exceptions.hpp \
				 ./includes/Headers.hpp

OBJS        =    ${addprefix objs/, ${SRCS:.cpp=.o}}

CC          =    c++

CFLAGS      =    -Wall -Werror -Wextra -std=c++98

RM          =    rm -rf

objs/%.o:	%.cpp ./includes/* Makefile
	@mkdir -p $(dir $@)             
	$(CC) ${CFLAGS} -c $< -o $@

all:	${NAME}

${NAME}:	${OBJS} ${INCLUDES}         
	$(CC) ${CFLAGS} -o $(NAME) ${OBJS}

clean:
	${RM} objs/

fclean:	clean 
	${RM} ${NAME}

re:	fclean all

.PHONY:		all clean fclean re