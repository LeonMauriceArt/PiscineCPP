# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmaurin- <lmaurin-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 14:24:21 by lmaurin-          #+#    #+#              #
#    Updated: 2023/03/22 15:06:10 by lmaurin-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= Zombies

INCLUDES	:= 	Zombie.hpp

SRC			:= 	randomChump.cpp \
				Zombie.cpp \
				newZombie.cpp \
				main.cpp 
		
OBJ 		:= 	$(SRC:.c=.o)
CC 			:= c++
CFLAGS 		:= -Wall -Wextra -Werror -std=c++98

HEADER 		:= 	$(addprefix includes/,$(INCLUDES))
MEMFLAGS 	:= 	-fsanitize=address -g3

all: $(NAME)
	@echo "\033[32mCompilation done !\033[0m"

$(OPATH)/%.o 	: %.c $(HEADER) Makefile
	@echo "Compiling $<..."
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@


zombies: $(SRC)
	@echo "Compiling $<..."	
	@$(CC) $(CFLAGS) -o $@ $<


$(NAME) 		: $(OBJ)
	@echo "Compiling $<..."	
	@$(CC) $(CFLAGS) $^ -o $@ $(MLXFLAGS)

clean:
	@echo "Cleaning..."
	@rm -f $(NAME)

fclean 			: clean
	@echo "Force Cleaning..."
	@rm $(NAME) || true

re: fclean all


.PHONY 			: clean fclean re