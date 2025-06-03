#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

# define ERR_ARGS "Wrong numbers of args, try with ./harlFilter <MSG>\nDEBUG - INFO - WARNING - ERROR\n"
# define DEBUG_MSG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do!"
# define INFO_MSG "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
# define WARNING_MSG "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month."
# define ERROR_MSG "This is unacceptable! I want to speak to the manager now."
# define UNEXPECTED_ARGS "[ Probably complaining about insignificant problems ]\n"

#define RESET       "\033[0m"

#define BOLD_BRIGHT_RED	"\033[1;91m"
#define BRIGHT_ORANGE	"\033[1;93m"
#define BRIGHT_GREEN    "\033[1;92m"
#define BRIGHT_BLUE     "\033[1;94m"

class Harl {

private:

	void	debug();
	void	info();
	void	warning();
	void	error();

public:

	Harl();
	~Harl();
	void	complain(std::string level);

};

typedef void (Harl::*HarlFunction)();

#endif
