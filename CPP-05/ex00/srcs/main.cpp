#include "../includes/Bureaucrat.hpp"

int main(void) {
	sep("Default and Name ctor", 40);
	try {
		{
			Bureaucrat default_b;
			std::cout << default_b;
		}
		{
			Bureaucrat b("Johnny", 1);
			std::cout << b;
		}
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	sep("To high and to low ctor", 40);
	try {
		{
			Bureaucrat b("James", -1);
		}
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		{
			Bureaucrat b("Michael", 151);
		}
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	sep("Increment and decrement", 40);
	try {
		{
			Bureaucrat b("William", 2);
			std::cout << b;
			b.incrementGrade(1);
			std::cout << b;
		}
		std::cout << std::endl;
		{
			Bureaucrat b("David", 149);
			std::cout << b;
			b.decrementGrade(1);
			std::cout << b;
		}
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	sep("Increment to much", 40);
	try {
		{
			Bureaucrat b("Sarah", 2);
			std::cout << b;
			b.incrementGrade(2);
			std::cout << b;
		}
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	sep("Decrement to much", 40);
	try {
		{
			Bureaucrat b("Emily", 149);
			std::cout << b;
			b.decrementGrade(2);
			std::cout << b;
		}
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
