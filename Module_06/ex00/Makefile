CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g
INCLUDES = Converter.hpp
SOURCES = main.cpp Converter.cpp
OBJECTS = $(SOURCES:.cpp=.o)
NAME = convert

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
