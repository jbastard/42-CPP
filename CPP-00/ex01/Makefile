NAME = phonebook

#COMPILATION
CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -Iincludes -std=c++98

#FILES_DIR
SRC_DIR = srcs/
OBJ_DIR = obj/

#FILES
SRC =	phonebook.cpp \
		main.cpp

SRCS		=	$(addprefix $(SRC_DIR), $(SRC))
OBJS		=	$(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
