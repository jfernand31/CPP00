NAME := phonebook
CC := c++
CCFLAGS := -Wall -Wextra -Werror -std=c++98
CFILES := Contact.cpp main.cpp PhoneBook.cpp
OFILES := $(CFILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OFILES)
	$(CC) $(CCFLAGS) $(OFILES) -o $(NAME)

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
