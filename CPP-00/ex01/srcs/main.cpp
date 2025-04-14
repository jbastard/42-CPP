
#include "../includes/Phonebook.hpp"

std::string itoa(int value) {
	std::ostringstream oss;
	oss << value;
	return oss.str();
}

int is_digits(std::string str) {
	for (int i = 0; i < (int)str.length(); i++)
		if (!isdigit(str[i]))
			return 0;
	return 1;
}

std::string	formatString(std::string str, int caseWidth, std::string center) {
	std::string ret;
	int padding = caseWidth - str.length();
	int len = (int)str.length();

	if ((int)str.length() > caseWidth)
		ret = str.substr(0, caseWidth - 1) + '.';
	else {
		ret = std::string(caseWidth, ' ');
		if (center == "right")
			for(int i = 0; i < len; i++)
				ret[padding + i] = str[i];
		else if (center == "left")
			for(int i = 0; i < len; i++)
				ret[i] = str[i];
		else if (center == "midle")
			for (int i = 0; i < len; i++)
				ret[i + padding / 2] = str[i];
	}
	return (ret);
}

void	displayContactBar(Contact contact, int contactCount, int caseWidth, std::string center) {
	std::cout
		<< "|"
		<< formatString(itoa(contactCount + 1), caseWidth, "midle") << "|"
		<< formatString(contact.getContactInfos(FIRST_NAME), caseWidth, center) << "|"
		<< formatString(contact.getContactInfos(LAST_NAME), caseWidth, center) << "|"
		<< formatString(contact.getContactInfos(NICKNAME), caseWidth, center) << "|"
		<< std::endl;
}

void	displayLine(int caseWidth) {
	std::string line = std::string(caseWidth, '-');
	char		pipe = '|';
	std::cout << pipe
	<< line << pipe
	<< line << pipe
	<< line << pipe
	<< line << pipe
	<< std::endl;
}

void	displayIndex(int caseWidth) {
	std::cout << "|"
	<< formatString("index", caseWidth, "midle") << "|"
	<< formatString("first name", caseWidth, "midle") << "|"
	<< formatString(" last name", caseWidth, "midle") << "|"
	<< formatString("nickname", caseWidth, "midle") << "|"
	<< std::endl;
	displayLine(caseWidth);
}

void	displayContactInfos(Contact contact) {
	std::cout << formatString("First name", 16, "left")
	<< ": " << contact.getContactInfos(FIRST_NAME) << std::endl;
	std::cout << formatString("Last name", 16, "left")
	<< ": " << contact.getContactInfos(LAST_NAME) << std::endl;
	std::cout << formatString("Nickname", 16, "left")
	<< ": " << contact.getContactInfos(NICKNAME) << std::endl;
	std::cout << formatString("Phone number", 16, "left")
	<< ": " << contact.getContactInfos(PHONE_NUM) << std::endl;
	std::cout << formatString("Darkets secret", 16, "left")
	<< ": " << contact.getContactInfos(D_SECRET) << std::endl << std::endl;
}

void findContact(PhoneBook phonebook) {
	std::string research;
	int index = 0;

	std::cout << "Enter contact ID / Name: ";
	std::getline(std::cin, research);
	index = atoi(research.c_str());
	if (is_digits(research) && (index >= 1 && index <= 9))
		displayContactInfos(phonebook.getContact(index - 1));
}

void	search(PhoneBook phoneBook, int contactCount, int caseWidth, std::string center)
{
	Contact	contact;

	displayLine(caseWidth);
	displayIndex(caseWidth);
	while (contactCount--) {
		contact = phoneBook.getContact(contactCount);
		displayContactBar(contact, contactCount, caseWidth, center);
		displayLine(caseWidth);
	}
	findContact(phoneBook);
}

int		add(PhoneBook *phonebook, int contactCount) {
	phonebook->newContact(contactCount);
	return (1);
}

int		main(int ac, char **av) {
	int 		contactCount = 0;
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
		if (contactCount == 8)
			contactCount = 0;
		std::cout << "Enter command: " << std::endl;
		std::cin >> command;
		std::cin.ignore();
		if (std::cin.eof())
			break;
		if (command == "ADD" || command == "add")
			add(&phoneBook, contactCount++);
		else if (command == "SEARCH" || command == "search")
			search(phoneBook, contactCount, caseWitdh, center);
		else if (command == "EXIT" || command == "exit")
			break;
		else
			std::cout << "command not found: " << command << std::endl;
	}
	return (0);
}
