
#include "../includes/Phonebook.hpp"

int		main(int ac, char **av)
{
	int 		contactCount = 0;
	int 		contactFull = 0;
	int			caseWitdh = 10;
	std::string	center = "right";
	PhoneBook	phoneBook;
	std::string	command;

	if (ac > 1)
		caseWitdh = atoi(av[1]);
	if (ac > 2)
		center = av[2];
	if (ac > 3)
		std::cout << "Wrong number of args, try ./phonebook [case-width] [centered]";
	while (true) {
		if (contactCount == 8) {
			contactFull = 1;
			contactCount = 0;
		}
		std::cout << "Enter command: " << std::endl;
		std::cin >> command;
		std::cin.ignore();
		if (std::cin.eof())
			break;
		if (command == "ADD" || command == "add")
			add(&phoneBook, contactCount++);
		else if (command == "SEARCH" || command == "search")
			search(phoneBook, contactCount, contactFull, caseWitdh, center);
		else if (command == "EXIT" || command == "exit")
			break;
		else
			std::cout << "command not found: " << command << std::endl;
	}
	return (0);
}
