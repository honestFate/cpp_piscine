CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SOURCES = megaphone.cpp
OBJECTS = $(SOURCES:.cpp=.o)
NAME = megaphone

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) -v
	$(CC) $(CFLAGS) $^ -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re