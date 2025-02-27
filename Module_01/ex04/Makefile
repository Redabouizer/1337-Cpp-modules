NAME = main

FILES = main.cpp

SRCS = $(FILES:.cpp=.o)

CC = c++ 

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRCS)
	@$(CC) $(CPPFLAGS) $^ -o $@

%.o: %.c
	@$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(SRCS)

fclean: clean
	rm -rf $(NAME)
	rm -rf *.replace

re: fclean all