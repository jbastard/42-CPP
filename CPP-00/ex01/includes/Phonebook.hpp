
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <cstring>
# include <cstdlib>

# include "Contact.hpp"

class	PhoneBook {
private:
	Contact contact[8];
public:
	PhoneBook();
	~PhoneBook();
};

#endif
