NAME := megaphone

CPPC := c++
CPPFLAGS := -Wall -Wextra -Werror -std=c++98

SRC_FILES := megaphone.cpp
OBJ_FILES := $(SRC_FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
		@echo "Linking $(NAME)..."
		@$(CPPC) $(CPPFLAGS) $(OBJ_FILES) -o $(NAME)

%.o: %.cpp
		@$(CPPC) $(CPPFLAGS) -c $< -o $@

clean:
		@rm -rf $(OBJ_FILES)

fclean: clean
		@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
