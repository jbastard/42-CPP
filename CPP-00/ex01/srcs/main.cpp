
#include "../includes/Phonebook.hpp"

// Le fill info fonctionne, le probleme est après...

int		add(PhoneBook phonebook, int contactCount) {
	phonebook.newContact(contactCount);
	return (1);
}

void	search(PhoneBook phoneBook, int contactCount)
{
	Contact	contact;

	std::cout << HBAR << std::endl;
	std::cout << "|" << "  index   " << "|" << "first name" << "|" << " nickname " << "|" << "phone num " << "|" << std::endl;
	std::cout << HBAR << std::endl;
	while (contactCount--) {
		contact = phoneBook.getContact(contactCount);
		std::cout << "|" << contact.getContactInfos(FIRST_NAME) << "|" << std::endl;
		std::cout << HBAR << std::endl;
	}
}

int		main() {
	PhoneBook	phoneBook;
	int 		contactCount = 0;
	std::string	command;

	while (true) {
		if (contactCount == 8)
			contactCount = 0;
		std::cout << "Enter command: " << std::endl;
		std::cin >> command;
		std::cin.ignore();
		if (std::cin.eof())
			break;
		if (command == "ADD" || command == "add")
			add(phoneBook, contactCount++);else
		if (command == "SEARCH" || command == "search")
			search(phoneBook, contactCount);else
		if (command == "EXIT" || command == "exit")
			break;
		else
			std::cout << "command not found: " << command << std::endl;
	}
	return (0);
}
