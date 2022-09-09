CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g
INCLUDES = AAnimal.hpp Cat.hpp Dog.hpp Brain.hpp
SOURCES = main.cpp AAnimal.cpp Cat.cpp Dog.cpp Brain.cpp
OBJECTS = $(SOURCES:.cpp=.o)
NAME = zoo

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CXXFLAGS) $(OBJECTS) -o $(NAME)

%.o: %.cpp $(INCLUDES)
	$(CC) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
