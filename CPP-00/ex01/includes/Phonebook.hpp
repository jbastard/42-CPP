
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <cstring>
# include <sstream>
# include <cstdlib>
# include <iomanip>
# include "Contact.hpp"

# define HBAR "|----------|----------|----------|----------|"
# define FIRST_NAME 1
# define LAST_NAME 2
# define NICKNAME 3
# define PHONE_NUM 4
# define D_SECRET 5

#define BG_WHITE    "\033[47m"
#define RESET       "\033[0m"
#define BRIGHT_WHITE     "\033[97m"

class	PhoneBook {
private:
	Contact contact[8];
public:
	void	newContact(int contactCount);
	Contact &getContact(int index);
	PhoneBook();
	~PhoneBook();
};

//DISPLAY.C
std::string	formatString(std::string str, int caseWidth, const std::string& center);
void		displayContactBar(Contact contact, int contactCount, int caseWidth, const std::string& center);
void		displayLine(int caseWidth);
void		displayIndex(int caseWidth);
void		displayContactInfos(Contact contact);
//COMMAND.C
void		findContact(PhoneBook phonebook, int contactFull, int contactCount);
void		search(PhoneBook phoneBook, int contactCount, int contactFull, int caseWidth, const std::string& center);
int			add(PhoneBook *phonebook, int contactCount);

#endif
