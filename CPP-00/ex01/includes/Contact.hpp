
#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "Phonebook.hpp"

class Contact {
private:
	std::string	_lastName;
	std::string	_name;
	std::string	_nickName;
	std::string	_phoneNumber;
	std::string	_darkestSecret;
public:
	std::string	getContactInfos(int which);
	void fillInfos();
	Contact();
	~Contact();
};

#endif
