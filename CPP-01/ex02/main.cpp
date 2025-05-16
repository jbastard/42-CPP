
# include <iostream>

# define RESET "\033[0m"
# define GREEN "\033[92m"
# define RED "\033[91m"
# define BLUE "\033[94m"

int		main()
{
	std::string str = "HI THIS IS BRAIN";

	std::string *str_pointer = &str;
	std::string &str_reference = str;
	std::cout << "String adress    : " << GREEN << &str << RESET << std::endl;
	std::cout << "Reference adress : " << GREEN << &str_reference << RESET << std::endl;
	std::cout << "Pointer adress   : " << RED << &str_pointer << RESET << std::endl << std::endl;

	std::cout << "String value     : " << BLUE << str << RESET << std::endl;
	std::cout << "Reference value  : " << BLUE << str_reference << RESET << std::endl;
	std::cout << "Pointer value    : " << BLUE << *str_pointer << RESET << std::endl;

	return (0);
}
