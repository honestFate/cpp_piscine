CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g
INCLUDES = generator.hpp identifier.hpp Base.hpp A.hpp B.hpp C.hpp
SOURCES = main.cpp generator.cpp identifier.cpp Base.cpp A.cpp B.cpp C.cpp
OBJECTS = $(SOURCES:.cpp=.o)
NAME = dynamic

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
