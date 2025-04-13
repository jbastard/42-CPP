
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <cstring>
# include <cstdlib>
#include <iomanip>
# include "Contact.hpp"

# define HBAR "|----------|----------|----------|----------|"
# define FIRST_NAME 1
# define LAST_NAME 2
# define NICKNAME 3
# define PHONE_NUM 4
# define D_SECRET 5

class	PhoneBook {
private:
	Contact contact[8];
public:
	void	newContact(int contactCount);
	Contact &getContact(int index);
	PhoneBook();
	~PhoneBook();
};

#endif
