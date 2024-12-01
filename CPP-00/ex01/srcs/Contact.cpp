
#include "../includes/Phonebook.hpp"

Contact::~Contact() {}

Contact::Contact() {}

std::string	Contact::getContactInfos(int which) {
	if (which == FIRST_NAME)
		return (this->_name);
	if (which == LAST_NAME)
		return (this->_lastName);
	if (which == NICKNAME)
		return (this->_nickName);
	if (which == PHONE_NUM)
		return (this->_phoneNumber);
	if (which == D_SECRET)
		return (this->_darkestSecret);
	return (NULL);
}

void Contact::fillInfos() {
	std::cout << "Enter contact name: ";
	std::getline(std::cin, this->_name);
	std::cout << "Enter contact last name: ";
	std::getline(std::cin, this->_lastName);
	std::cout << "Enter " << this->_name << "'s Nickname: ";
	std::getline(std::cin, this->_nickName);
	std::cout << "Enter " << this->_name << "'s Phone number: ";
	std::getline(std::cin, this->_phoneNumber);
	std::cout << "Enter " << this->_name << "'s Darkest Secret: ";
	std::getline(std::cin, this->_darkestSecret);
	std::cout << std::endl;
}
