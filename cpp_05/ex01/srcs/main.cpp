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
	/* 
	TEST 1, EVERYTHING SHOULD WORK, SHOWS BUREAUCRAT INIT, OPERATOR OVERLOAD,
	GRADE INCREMENTS, FORM SIGNING PROCESS, CATCHING AN EXTRA EXCEPTION CALLED
	ALREADY SIGNED EXCEPTION.
	*/ 

	try
	{
		print("bureaucrat");
		Bureaucrat crat1("Billy Butcher", 50);
		std::cout << crat1;
		print("form");
		Form test("Test Form", 10, 10);
		std::cout << test;

		print("action");
		crat1.incrementGrade(30);
		std::cout << "After promotion: " << crat1 << std::endl;
		crat1.incrementGrade(10);
		std::cout << "After promotion: " << crat1 << std::endl;
		crat1.incrementGrade(9);
		crat1.signForm(test);
		std::cout << std::endl;
		std::cout << "After promotion: " << crat1 << std::endl;
		crat1.signForm(test);
	}
	catch (std::exception& crat1)
	{
		std::cerr << "Error catched : " << crat1.what() << std::endl;
	}

	/*
	TEST 2 : TRYING TO INIT A BUREAUCRAT WITH A GRADE THAT DO NOT ALLOWS HIM TO BE 
	INITIATED, CATCHING A GLOBAL EXCEPTION
	*/

	try
	{
		print("bureaucrat");
		std::cout << "Trying to init Jojo le demago with a grade of : 151." << std::endl << std::endl;
		Bureaucrat crat2("Jojo le demago", 151);
	}
	catch (std::exception& crat2)
	{
		std::cerr << "Error catched : " << crat2.what() << std::endl;
	}
	
	/*
	TEST 3 : TO DEMONSTRATE PARTICULAR CATCH, WE'LL INITIATE A BUREAUCRAT THAT CANNOT
	SIGN A FORM BECAUSE ITS GRADE IT TOO LOW, BUT WE'LL TRY TO CATCH A GRADE TOO LOW
	ON THE FORM OBJECT FIRST, IT WILL FAIL BECAUSE WE ARE ALREADY CATCHING IT LOCALLY
	IN THE signForm() METHOD. THE PURPOSE IS TO DEMONSTRATE THAT IF WE ARE CATCHING AN 
	EXCEPTION IN A CALLED FUNCTION, IT WILL NOT BE CATCHED AGAIN IN THE MAIN.
	*/

	try
	{
		print("bureaucrat");
		Bureaucrat crat3("Jaja la demaga", 11);
		std::cout << crat3;
		print("form");
		Form test2("Test Form 2", 10, 10);
		std::cout << test2;
		print("action");
		crat3.signForm(test2);
	}
	catch (const Form::GradeTooLowException& e)
	{
		std::cerr << "Into Form::GradeTooLowException" << std::endl;	
	}
	catch (std::exception& e)
	{
		std::cerr << "Error catched : " << e.what() << std::endl;
	}

	/*
	TEST 4 : THIS TIME WE'LL BE TRYING TO DO A PARTICULAR CATCH ON AN ALREADY
	SIGNED EXCEPTION BEFORE MAKING IT TO THE GLOBAL EXCEPTION, AS WE'RE NOT CATCHING
	AN ALREADY SIGNED IN THE signForm() METHOD, IT WILL BE ABLE TO BE CATCHED IN THE MAIN
	THIS TIME.
	*/

	try
	{
		print("bureaucrat");
		Bureaucrat crat4("Jiji le p'tit kiwi", 1);
		std::cout << crat4;	
		print("form");
		Form test3("Test Form 3", 2, 2);
		std::cout << test3;
		print("action");
		crat4.signForm(test3);
		crat4.signForm(test3);
	}
	catch (Form::AlreadySignedException& e)
	{
		std::cerr << "Into Form::AlreadySignedException" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Error catched : " << e.what() << std::endl;
	}	
	std::cout << "------------------------------------------------" << std::endl;
	return 0;
}
