#include "../includes/Bureaucrat.hpp"
#include "../includes/Colors.hpp"

void print(std::string type)
{
	if (type == "bureaucrat")
	{
		std::cout << YELLOW "------------------------------------------------" << std::endl;
		std::cout << "----------------- INIT BUREAUCRAT --------------" << std::endl;
		std::cout << "------------------------------------------------" RESET << std::endl;
	}
	else if (type == "form")
	{
		std::cout << YELLOW "------------------------------------------------" << std::endl;
		std::cout << "-------------------- INIT FORM -----------------" << std::endl;
		std::cout << "------------------------------------------------" RESET << std::endl;
	}
	else if (type == "action")
	{
		std::cout << YELLOW "------------------------------------------------" << std::endl;
		std::cout << "--------------------- ACTIONS ------------------" << std::endl;
		std::cout << "------------------------------------------------" RESET << std::endl;
	}
}

int main(void)
{
	try
	{
		print("bureaucrat");
		Bureaucrat crat1("Billie Butcher", 50);
		Bureaucrat crat2(crat1);
		Bureaucrat crat3 = crat1;
		std::cout << crat1 << std::endl;
		std::cout << crat2 << std::endl;
		std::cout << crat3 << std::endl;

		print("action");
		crat1.incrementGrade(30);
		std::cout << "After promotion: " << crat1 << std::endl;
		crat1.incrementGrade(10);
		std::cout << "After promotion: " << crat1 << std::endl;
		crat1.incrementGrade(9);
		std::cout << "After promotion: " << crat1 << std::endl;
		// crat1.incrementGrade(1);
		// std::cout << "After promotion: " << crat1 << std::endl;
		crat1.decrementGrade(10);
		std::cout << "After relagation: " << crat1 << std::endl;
	}
	catch (std::exception& crat1)
	{
		std::cerr << "Error catched :" << crat1.what() << std::endl;
	}

	std::cout << "------------------------------------------------" << std::endl;

	try
	{
		Bureaucrat crat2("Jojo le demago", 0);
	}
	catch (std::exception& crat2)
	{
		std::cerr << "Error catched :" << crat2.what() << std::endl;
	}

	return 0;
}
