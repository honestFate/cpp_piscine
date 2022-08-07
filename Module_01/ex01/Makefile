CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDES = Zombie.hpp
SOURCES = main.cpp Zombie.cpp zombieHorde.cpp
OBJECTS = $(SOURCES:.cpp=.o)
NAME = brainz

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
