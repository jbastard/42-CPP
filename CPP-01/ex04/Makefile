# NAME OF THE EXECUTABLE
NAME = sed_is_for_losers

# COMPILER & FLAGS
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -Iincludes -std=c++98

# DIRECTORIES
SRC_DIR = /
OBJ_DIR = objs

# SOURCE FILES
SRC = 	main \

# FULL PATHS
SRCS = $(addsuffix .cpp, $(SRC))
OBJS = $(patsubst /%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# DEFAULT TARGET
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# COMPILATION
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
