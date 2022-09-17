CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g
INCLUDES = Span.hpp
SOURCES = main.cpp Span.cpp
OBJECTS = $(SOURCES:.cpp=.o)
NAME = span

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
