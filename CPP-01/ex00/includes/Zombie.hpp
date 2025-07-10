
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

# define RESET "\033[0m"
# define GREEN "\033[92m"
# define RED "\033[91m"
# define BLUE "\033[94m"

class Zombie {
private:

	std::string	_name;

public:

	Zombie();
	Zombie(std::string name);
	~Zombie();

	void	announce(void);

};

void	randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif
