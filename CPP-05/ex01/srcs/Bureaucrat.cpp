#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

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
	}
	return *this;
}

const std::string& Bureaucrat::getName() const { return this->_name; }
int Bureaucrat::getGrade() const { return this->_grade; }

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

void Bureaucrat::signForm(Form& f) {
	try {
		f.beSigned(*this);
		std::cout << BRIGHT_BLUE << this->_name << RESET << BRIGHT_GREEN" signed " BRIGHT_MAGENTA << f.getName() << RESET << std::endl << std::endl;
	} catch (const std::exception& e) {
		std::cout
				<< BRIGHT_BLUE << this->_name << BRIGHT_RED" couldn’t sign " RESET
			<< BRIGHT_MAGENTA << f.getName() << RESET
			<< " because " << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return BRIGHT_RED "Bureaucrat: grade too low\n" RESET;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return BRIGHT_RED  "Bureaucrat: grade too high\n" RESET;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &src) {
	out
		<< BRIGHT_BLUE << src.getName()
		<< BRIGHT_WHITE  " bureaucrat grade " BRIGHT_BLUE << src.getGrade()
		<< RESET << std::endl;
	return out;
}
