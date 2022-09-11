CC = c++
CXXFLAGS = -Wall -Werror -std=c++98 -g
SOURCES = main.cpp ClapTrap.cpp ScavTrap.cpp
OBJECTS = $(SOURCES:.cpp=.o)
NAME = ScavTrap

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CXXFLAGS) $^ -o $(NAME)

%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
