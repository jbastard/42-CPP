#pragma once

#include <string>
#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class AForm;

class Bureaucrat{
	private:
		const std::string name;
		int grade;
		Bureaucrat();
	public:
		~Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat& operator=(const Bureaucrat& other);
		const std::string& getName() const;
		int getGrade() const;
		void incrementGrade(int amount);
		void decrementGrade(int amount);
		void signForm(AForm& form);
		void executeForm(const AForm& form) const;
		class GradeTooHighException : public std::exception{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& crat);
