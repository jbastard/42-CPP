
#include "../includes/Phonebook.hpp"

int is_digits(std::string str)
{
    for (int i = 0; i < (int)str.length(); i++)
        if (!isdigit(str[i]))
            return 0;
    return 1;
}

void findContact(PhoneBook phonebook,
                    int contactFull,
                    int contactCount)
{
    std::string research;
    int index = 0;

    std::cout << "Enter contact ID: ";
    std::getline(std::cin, research);
    index = atoi(research.c_str());
    if (is_digits(research) && (index >= 1 && index <= 9) && contactFull)
        displayContactInfos(phonebook.getContact(index - 1));
    else if (is_digits(research) && index <= contactCount && index >= 1)
        displayContactInfos(phonebook.getContact(index - 1));
    else if (research == "exit")
        return ;
    else
        std::cout << "Invalid ID" << std::endl;
}

void	search(PhoneBook phoneBook,
                int contactCount,
                int contactFull,
                int caseWidth,
                const std::string& center)
{
    Contact	contact;
    int i = 0;

    displayLine(caseWidth);
    displayIndex(caseWidth);
    while ((i < contactCount || i < 8) && (contactFull || i < contactCount)) {
        contact = phoneBook.getContact(i);
        displayContactBar(contact, i, caseWidth, center);
        displayLine(caseWidth);
        i++;
    }
    findContact(phoneBook, contactFull, contactCount);
}

int		add(PhoneBook *phonebook, int contactCount)
{
    phonebook->newContact(contactCount);
    return (1);
}
