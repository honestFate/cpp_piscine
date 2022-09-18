CC = c++
CXXFLAGS = -Wall -Werror -std=c++98 -g
INCLUDES = ClapTrap.hpp ScavTrap.hpp FlagTrap.hpp DiamondTrap.hpp
SOURCES = main.cpp ClapTrap.cpp ScavTrap.cpp FlagTrap.cpp DiamondTrap.cpp
OBJECTS = $(SOURCES:.cpp=.o)
NAME = DiamondTrap

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CXXFLAGS) $^ -o $(NAME)

%.o: %.cpp $(INCLUDES)
	$(CC) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
