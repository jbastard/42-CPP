#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
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

	/*
	ALL THE FORM REQUIRED BY THE SUBJECTS ARE HERE SIGNED AND EXECUTED WIHTOUT
	PROBLEMS TO SHOW "NORMAL" OUTPUTS.
	*/

	try
	{
		print("bureaucrat");
		Bureaucrat crat1("Jojo le demago", 1);
		std::cout << crat1;
		print("form");
		ShrubberyCreationForm shrub("Shrub Target");
		std::cout << shrub;
		PresidentialPardonForm pres("Pres Target");
		std::cout << pres;
		RobotomyRequestForm robotomy("Robotomy Target");
		std::cout << robotomy;
		print("execute");
		print("shrub");
		crat1.signForm(shrub);
		crat1.executeForm(shrub);
		print("pres");
		crat1.signForm(pres);
		crat1.executeForm(pres);
		print("robotomy");
		crat1.signForm(robotomy);
		crat1.executeForm(robotomy);
		crat1.executeForm(robotomy);
	}
	catch (std::exception& e)
	{
		std::cout << "Error catched : " << e.what() << std::endl;
	}

	/*
	HERE, SIGN CAN SIGN THE PRESIDENTIAL FORM BUT CANNOT EXECUTE IT, THIS TEST
	WILL SHOW THAT A FORM MUST BE SIGNED IN ORDER TO BE EXECUTED AND ONCE SIGNED
	CAN BE EXECUTED BY A BUREAUCRAT WHO HAS THE REQUIRED GRADE.
	*/

	try
	{
		print("bureaucrat");
		Bureaucrat sign("Sign", 25);
		Bureaucrat exec("Exec", 5);
		std::cout << sign;
		std::cout << exec;
		print("pres");
		PresidentialPardonForm pres("Pres Target");
		std::cout << pres;
		print("action");
		exec.executeForm(pres);
		sign.signForm(pres);
		sign.executeForm(pres);
		// exec.signForm(pres);
		exec.executeForm(pres);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error catched : " << e.what() << std::endl;
	}

}
