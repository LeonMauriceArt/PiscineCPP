# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmaurin- <lmaurin-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 19:24:43 by lmaurin-          #+#    #+#              #
#    Updated: 2023/03/20 19:24:44 by lmaurin-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= PhoneBook

INCLUDES	:= 	Contact.hpp

SRC			:= 	Contact.cpp \
				PhoneBook.cpp \
				main.cpp 
		
OBJ 		:= 	$(SRC:.c=.o)
CC 			:= c++
CFLAGS 		:= -Wall -Wextra -Werror -std=c++98

HEADER 		:= 	$(addprefix includes/,$(INCLUDES))
MEMFLAGS 	:= 	-fsanitize=address -g3

all: $(NAME)
	@echo "\033[32mCompilation done !\033[0m"

$(OPATH)/%.o 	: %.c $(HEADER) Makefile
	@echo "\033[34mCompiling $<...\033[0m"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@


phonebook: $(SRC)
	@echo "\033[34mCompiling $<...\033[0m"	
	@$(CC) $(CFLAGS) -o $@ $<


$(NAME) 		: $(OBJ)
	@echo "\033[34mCompiling $<...\033[0m"	
	@$(CC) $(CFLAGS) $^ -o $@ $(MLXFLAGS)

clean:
	@echo "\033[31mCleaning...\033[0m"
	@rm -f $(NAME)

fclean 			: clean
	@echo "\033[31mForce Cleaning...\033[0m"
	@rm $(NAME) || true

re: fclean all


.PHONY 			: clean fclean re