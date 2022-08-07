CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDES = PhoneBook.hpp Contact.hpp
SOURCES = main.cpp PhoneBook.cpp Contact.cpp
OBJECTS = $(SOURCES:.cpp=.o)
NAME = phonebook

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
