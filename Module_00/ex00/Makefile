
NAME = megaphone

FILES = megaphone.cpp

SRCS = $(FILES:.cpp=.o)

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRCS)
	@$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(SRCS)

fclean:
	rm -f $(SRCS) $(NAME)

re: fclean all