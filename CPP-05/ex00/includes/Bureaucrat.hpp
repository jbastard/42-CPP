#pragma once

#include "Colors.hpp"
#include <exception>
#include <string>
#include <iostream>

class Bureaucrat {

private:
	const std::string _name;
	int _grade;

public:

	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat &copy);
	~Bureaucrat();

	Bureaucrat &operator=(const Bureaucrat &src);

	const std::string& getName() const;
	unsigned int getGrade() const;

	void incrementGrade(int value);
	void decrementGrade(int value);

	class GradeTooHighException: public std::exception {
	public:
		virtual const char *what()const throw();
	};

	class GradeTooLowException: public std::exception {
	public:
		virtual const char *what()const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &src);