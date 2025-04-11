
#include "../includes/Phonebook.hpp"

PhoneBook::~PhoneBook() {}

PhoneBook::PhoneBook() {}

void	PhoneBook::newContact(int contactCount) {
	Contact NewContact;
	NewContact.fillInfos();
	this->contact[contactCount] = NewContact;
}
