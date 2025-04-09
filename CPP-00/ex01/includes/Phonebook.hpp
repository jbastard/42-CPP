
#ifndef MEGAPHONE_HPP
# define MEGAPHONE_HPP

# include <iostream>
# include "Contact.hpp"

class	PhoneBook
{
private:
	Contact	contact[8];
	int		contactCount = 8;
public:
	PhoneBook();
	~PhoneBook();
};

#endif
