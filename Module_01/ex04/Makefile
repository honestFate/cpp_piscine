CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDES = Sed.hpp
SOURCES = main.cpp Sed.cpp
OBJECTS = $(SOURCES:.cpp=.o)
SOURCES_TEST = _test.cpp Sed.cpp
OBJECTS_TEST = $(SOURCES_TEST:.cpp=.o)
NAME = seder
NAME_TESTER = _test

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CXXFLAGS) $^ -o $(NAME)

$(NAME_TESTER): $(OBJECTS_TEST)
	$(CC) $(CXXFLAGS) $^ -o $(NAME_TESTER)

%.o: %.cpp $(INCLUDES)
	$(CC) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)
	$(RM) $(OBJECTS_TEST)
	$(RM) test*

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_TESTER)

re: fclean all

.PHONY: all clean fclean re test
