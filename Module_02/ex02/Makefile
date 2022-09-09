CC = c++
CXXFLAGS = -Wall -Werror -std=c++98 -g
SOURCES = main.cpp Fixed.cpp
OBJECTS = $(SOURCES:.cpp=.o)
NAME = fixedPoint

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
