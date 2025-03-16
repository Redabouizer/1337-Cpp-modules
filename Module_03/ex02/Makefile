NAME = FragTrap

FILES = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp \

SRCS = $(FILES:.cpp=.o)

CC = c++ 

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRCS)
		@$(CC) $(CPPFLAGS) $^ -o $@

%.o: %.cpp ClapTrap.hpp ScavTrap.hpp FragTrap.hpp
		@$(CC) $(CPPFLAGS) -c $< -o $@

clean:
		rm -rf $(SRCS)

fclean: clean
		rm -rf $(NAME)

re: fclean all