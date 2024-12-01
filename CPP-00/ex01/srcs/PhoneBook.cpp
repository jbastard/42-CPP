
#include "../includes/Phonebook.hpp"

PhoneBook::~PhoneBook() {}

PhoneBook::PhoneBook() {}

Contact &PhoneBook::getContact(int index) {
	return (this->contact[index]);
}

void	PhoneBook::newContact(int contactCount) {
	Contact NewContact;
	NewContact.fillInfos();
	this->contact[contactCount] = NewContact;
}
