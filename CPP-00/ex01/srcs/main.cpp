
#include "../includes/Phonebook.hpp"

int	_add(PhoneBook phonebook, int contactCount) {
	std::cout << "Adding.." << std::endl;
	return (1);
}

int _search() {
	std::cout << "Searching.." << std::endl;
	return (1);
}

int main() {
	PhoneBook	phoneBook = PhoneBook();
	int 		contactCount = 0;
	std::string	command;

	while (1) {
		std::cout << "Enter command: " << std::endl;
		std::cin >> command;
		if (std::cin.eof())
			break ;
		if (!command.compare("ADD") || !command.compare("add")) {
			_add(phoneBook, contactCount);
			contactCount++; }
		else if (!command.compare("SEARCH") || !command.compare("search"))
			_search();
		else if (!command.compare("EXIT") || !command.compare("exit"))
			break ;
		else
			std::cout << "command not found: " << command << std::endl;
	}
	return (0);
}
