
#include "../includes/Phonebook.hpp"

int		add(PhoneBook phonebook, int contactCount) {
	phonebook.newContact(contactCount);
	return (1);
}

void	_search(PhoneBook phoneBook, int contactCount)
{
	(void)phoneBook;
	(void)contactCount;
	std::cout << HBAR << std::endl;
}

int		main() {
	PhoneBook	phoneBook;
	int 		contactCount = 0;
	std::string	command;

	while (true) {
		std::cout << "Enter command: " << std::endl;
		std::cin >> command;
		std::cin.ignore();
		if (std::cin.eof())
			break;
		if (command == "ADD" || command == "add")
			add(phoneBook, contactCount++);else
		if (command == "SEARCH" || command == "search")
			_search(phoneBook, contactCount);else
		if (command == "EXIT" || command == "exit")
			break;
		else
			std::cout << "command not found: " << command << std::endl;
	}
	return (0);
}
