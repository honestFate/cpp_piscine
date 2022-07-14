CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g
INCLUDES = Harl.hpp
SOURCES = main.cpp Harl.cpp
OBJECTS = $(SOURCES:.cpp=.o)
NAME = Harl_2.0

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
