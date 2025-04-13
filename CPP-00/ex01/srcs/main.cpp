
#include "../includes/Phonebook.hpp"

std::string itoa(int a)
{
	std::string ss="";
	while(a)
	{
		int x=a%10;
		a/=10;
		char i='0';
		i=i+x;
		ss=i+ss;
	}
	return ss;
}

std::string	*formatString(std::string str) {
	std::string *ret;
	int j = 0;
	int padding = 10 - str.length();

	if ((int)str.length() > 10)
		ret = new std::string(str.substr(0, 9) + '.');
	else {
		ret = new std::string(10, ' ');
		while (j < (int)str.length()) {
			(*ret)[padding + j] = str[j];
			j++;
		}
	}
	return (ret);
}

int		add(PhoneBook *phonebook, int contactCount) {
	phonebook->newContact(contactCount);
	return (1);
}

void	search(PhoneBook phoneBook, int contactCount)
{
	Contact	contact;

	std::cout << HBAR << std::endl;
	std::cout << "|"
		<< "  index   " << "|"
		<< "first name" << "|"
		<< " nickname " << "|"
		<< "phone num " << "|"
		<< std::endl;
	std::cout << HBAR << std::endl;
	while (contactCount--) {
		contact = phoneBook.getContact(contactCount);
		std::cout << "|"
			<< *formatString(itoa(contactCount + 1)) << "|"
			<< *formatString(contact.getContactInfos(FIRST_NAME)) << "|"
			<< *formatString(contact.getContactInfos(LAST_NAME)) << "|"
			<< *formatString(contact.getContactInfos(NICKNAME)) << "|"
			<< std::endl;
		std::cout << HBAR << std::endl;/
	}
}

int		main() {
	int 		contactCount = 0;
	PhoneBook	phoneBook;
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
			add(&phoneBook, contactCount++);else
		if (command == "SEARCH" || command == "search")
			search(phoneBook, contactCount);else
		if (command == "EXIT" || command == "exit")
			break;
		else
			std::cout << "command not found: " << command << std::endl;
	}
	return (0);
}
