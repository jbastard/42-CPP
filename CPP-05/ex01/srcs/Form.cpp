#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

Form::Form() : _name("Default"), _signed(false), _sign_grade(0), _exec_grade(0) {}

Form::Form(const std::string& name, int sign_grad, int exec_grade) : _name(name), _signed(false), _sign_grade(sign_grad), _exec_grade(exec_grade) {
	if (sign_grad > 150 || exec_grade > 150)
		throw Form::GradeTooLowException();
	if (sign_grad < 1 || exec_grade < 1)
		throw Form::GradeTooHighException();
}

Form::Form(const Form &src) {
	*this = src;
}

Form::~Form() {}

Form &Form::operator=(const Form &src) {
	if (this != &src) {
	}
	return *this;
}

const std::string&	Form::getName() const { return this->_name; }
int					Form::getSignGrade() const { return this->_sign_grade; }
int					Form::getExecGrade() const { return this->_exec_grade; }
bool				Form::isSigned() const { return this->_signed; }

void	Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > this->_sign_grade)
		throw Bureaucrat::GradeTooLowException();
	else this->_signed = !this->_signed;
}

const char* Form::GradeTooLowException::what() const throw() {
	return BRIGHT_RED "Form: grade too low\n" RESET;
}

const char* Form::GradeTooHighException::what() const throw() {
	return BRIGHT_RED  "Form: grade too high\n" RESET;
}

std::ostream &operator<<(std::ostream &out, const Form &src) {
	const std::string is_signed = (src.isSigned()) ? BRIGHT_GREEN"Yes" RESET : BRIGHT_RED"No" RESET;
	out
		<< BRIGHT_WHITE" Form       : " << BRIGHT_MAGENTA << src.getName() << RESET
		<< std::endl
		<< BRIGHT_WHITE " Signed     : " RESET << is_signed
		<< std::endl
		<< BRIGHT_WHITE " Sign grade : " RESET << src.getSignGrade()
		<< std::endl
		<< BRIGHT_WHITE " Exec grade : " RESET << src.getExecGrade()
		<< std::endl;
	return out;
}