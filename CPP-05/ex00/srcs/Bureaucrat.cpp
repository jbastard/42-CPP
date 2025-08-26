#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) {
	*this = src;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
	if (this != &src) {
		// Put Atributs here
	}
	return *this;
}

const std::string& Bureaucrat::getName() const { return this->_name; }

unsigned int Bureaucrat::getGrade() const { return this->_grade; }

void Bureaucrat::incrementGrade(int value) {
	this->_grade -= value;
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
}

void Bureaucrat::decrementGrade(int value) {
	this->_grade += value;
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return BRIGHT_RED "Bureaucrat: grade too low" RESET;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return BRIGHT_RED  "Bureaucrat: grade too high" RESET;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &src) {
	out
		<< BRIGHT_BLUE << src.getName()
		<< BRIGHT_WHITE  " bureaucrat grade " BRIGHT_BLUE << src.getGrade()
		<< RESET << std::endl;
	return out;
}
