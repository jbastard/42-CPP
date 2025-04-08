
#ifndef MEGAPHONE_HPP
# define MEGAPHONE_HPP

# include <iostream>

class	PhoneBook
{
	private:

	public:
/*-------------Default-Constructor--------*/
		PhoneBook();
/*-------------Copy-Constructor-----------*/
		PhoneBook(const PhoneBook &src);
/*-------------Default-Destructor---------*/
		~PhoneBook();
/*-------------Assignment operator--------*/
		PhoneBook &operator=(const PhoneBook &src);
};

#endif
