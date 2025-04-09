
#include "../includes/Phonebook.hpp"

PhoneBook::~PhoneBook() {}

PhoneBook::PhoneBook() {}

int _search() {
	std::cout << "Searching.." << std::endl;
	return (1);
}

int	_add() {
	return (1);
}

int main() {
	PhoneBook phoneBook = PhoneBook();
	std::string command;

	while (1) {
		std::cout << "Enter command: " << std::endl;
		std::cin >> command;
		if (std::cin.eof())
			break ;
		if (!command.compare("ADD") || !command.compare("add"))
			_add();
		else if (!command.compare("SEARCH") || !command.compare("search"))
			_search();
		else if (!command.compare("EXIT") || !command.compare("exit"))
			break ;
		else
			std::cout << "command not found: " << command << std::endl;
	}
	return (0);
}
