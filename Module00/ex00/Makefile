CC = c++
CFLAGS = -Wall -Wextra -Werror

all: megaphone
	@echo "\033[32mCompilation done !\033[0m"

megaphone: megaphone.cpp
	@echo "\033[34mCompiling $<...\033[0m"	
	@$(CC) $(CFLAGS) -o $@ $<

clean:
	@echo "\033[31mCleaning...\033[0m"
	@rm -f megaphone

re: clean all