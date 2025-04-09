
#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "Phonebook.hpp"

class Contact {
private:
	std::string	_name;
	std::string	_nickname;
	int			_phoneNumber;
	std::string	_darkestSecret;
public:
	Contact();
	Contact(const Contact&);
	~Contact();
};

#endif
