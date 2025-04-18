
#include "../includes/Phonebook.hpp"

std::string itoa(int value)
{
	std::ostringstream oss;
	oss << value;
	return oss.str();
}

std::string	formatString(std::string str,
							int caseWidth,
							const std::string& center)
{
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
		else if (center == "middle")
			for (int i = 0; i < len; i++)
				ret[i + padding / 2] = str[i];
	}
	return (ret);
}

void	displayContactBar(Contact contact,
							int contactCount,
							int caseWidth,
							const std::string& center)
{
	std::cout
		<< BG_WHITE << "|" << RESET
		<< formatString(itoa(contactCount + 1), caseWidth, "middle") << BG_WHITE << "|" << RESET
		<< formatString(contact.getContactInfos(FIRST_NAME), caseWidth, center) << BG_WHITE << "|" << RESET
		<< formatString(contact.getContactInfos(LAST_NAME), caseWidth, center) << BG_WHITE << "|" << RESET
		<< formatString(contact.getContactInfos(NICKNAME), caseWidth, center) << BG_WHITE << "|" << RESET
		<< std::endl;
}

void	displayLine(int caseWidth)
{
	std::string line = std::string(caseWidth, '-');
	char		pipe = '|';
	std::cout << BG_WHITE << pipe
	<< line << pipe
	<< line << pipe
	<< line << pipe
	<< line << pipe
	<< RESET << std::endl;
}

void	displayIndex(int caseWidth)
{
	std::cout << BG_WHITE << "|" << RESET
	<< formatString("index", caseWidth, "middle") << BG_WHITE << "|" << RESET
	<< formatString("first name", caseWidth, "middle") << BG_WHITE << "|" << RESET
	<< formatString(" last name", caseWidth, "middle") << BG_WHITE << "|" << RESET
	<< formatString("nickname", caseWidth, "middle") << BG_WHITE << "|" << RESET
	<< std::endl;
	displayLine(caseWidth);
}

void	displayContactInfos(Contact contact)
{
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
