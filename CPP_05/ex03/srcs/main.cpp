#include "../includes/Bureaucrat.hpp"
#include "../includes/Intern.hpp"
#include "../includes/Colors.hpp"
#include <cstdlib>
#include <ctime>

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
	else if (type == "shrub")
	{
		std::cout << YELLOW "------------------------------------------------" << std::endl;
		std::cout << "---------------- SHRUBBERY FORM ----------------" << std::endl;
		std::cout << "------------------------------------------------" RESET << std::endl;
	}
	else if (type == "pres")
	{
		std::cout << YELLOW "------------------------------------------------" << std::endl;
		std::cout << "--------------- PRESIDENTIAL FORM --------------" << std::endl;
		std::cout << "------------------------------------------------" RESET << std::endl;
	}
	else if (type == "robotomy")
	{
		std::cout << YELLOW "------------------------------------------------" << std::endl;
		std::cout << "----------------- ROBOTOMY FORM ---------------" << std::endl;
		std::cout << "------------------------------------------------" RESET << std::endl;
	}
		else if (type == "execute")
	{
		std::cout << YELLOW "------------------------------------------------" << std::endl;
		std::cout << "---------------- EXECUTING FORMS ---------------" << std::endl;
		std::cout << "------------------------------------------------" RESET << std::endl;
	}
}

int main(void)
{
	srand(time(NULL));
	Intern someRandomIntern;
	AForm* rrf;
	AForm* ppf;
	AForm* scf;

	rrf = someRandomIntern.makeForm("Robotomy Request", "Bender_Robotomy");
	ppf = someRandomIntern.makeForm("Presidential Pardon", "Bender_Pres");
	scf = someRandomIntern.makeForm("Shrubbery Creation", "Bender_Shrub");

	if (rrf &&  ppf && scf)
	{
		print("form");
		std::cout << *rrf;
		std::cout << *ppf;
		std::cout << *scf;
		try
		{
			print("bureaucrat");
			Bureaucrat crat("Jojo le demago", 1);
			std::cout << crat;
			print("action");
			crat.signForm(*rrf);
			crat.signForm(*ppf);
			crat.signForm(*scf);
			crat.executeForm(*rrf);
			crat.executeForm(*ppf);
			crat.executeForm(*scf);
		}

		catch(const std::exception& e)
		{
			std::cerr << "Error catched : " << e.what() << std::endl;
		}
	}
	delete rrf;
	delete ppf;
	delete scf;
}
