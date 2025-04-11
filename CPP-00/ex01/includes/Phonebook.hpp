
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <cstring>
# include <cstdlib>

# include "Contact.hpp"
#include <iomanip>

# define HBAR "|-------------------------------------------|"

class	PhoneBook {
private:
	Contact contact[8];
public:
	void	newContact(int contactCount);
	PhoneBook();
	~PhoneBook();
};

#endif
