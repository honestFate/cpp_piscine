CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDES = HumanA.hpp HumanB.hpp Weapon.hpp
SOURCES = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJECTS = $(SOURCES:.cpp=.o)
NAME = Unnecessary_violence

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
