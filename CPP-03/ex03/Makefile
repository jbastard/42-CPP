# NAME OF THE EXECUTABLE
NAME =  Nowit’sweird!

# COMPILER & FLAGS
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -Iincludes -std=c++98 -Wshadow

# DIRECTORIES
SRC_DIR = srcs
OBJ_DIR = objs

# SOURCE FILES
SRC = 	main \
		ClapTrap \
		ScavTrap \
		FragTrap \
		DiamondTrap \

# FULL PATHS
SRCS = $(addprefix $(SRC_DIR)/, $(addsuffix .cpp, $(SRC)))
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

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
