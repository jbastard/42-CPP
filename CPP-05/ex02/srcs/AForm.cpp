#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _signed(false), _sign_grade(0), _exec_grade(0) {}

AForm::AForm(const std::string& name, int sign_grad, int exec_grade) : _name(name), _signed(false), _sign_grade(sign_grad), _exec_grade(exec_grade) {
	if (sign_grad > 150 || exec_grade > 150)
		throw AForm::GradeTooLowException();
	if (sign_grad < 1 || exec_grade < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm &src) {
	*this = src;
}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &src) {
	if (this != &src) {
	}
	return *this;
}

const std::string&	AForm::getName() const { return this->_name; }
int					AForm::getSignGrade() const { return this->_sign_grade; }
int					AForm::getExecGrade() const { return this->_exec_grade; }
bool				AForm::isSigned() const { return this->_signed; }

void	AForm::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > this->_sign_grade)
		throw Bureaucrat::GradeTooLowException();
	else this->_signed = !this->_signed;
}

const char* AForm::GradeTooLowException::what() const throw() {
	return BRIGHT_RED "Form: grade too low\n" RESET;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return BRIGHT_RED  "Form: grade too high\n" RESET;
}

const char* AForm::NotSignedException::what() const throw() {
	return BRIGHT_RED  "Form: must be signed\n" RESET;
}

std::ostream &operator<<(std::ostream &out, const AForm &src) {
	const std::string is_signed = (src.isSigned()) ? BRIGHT_GREEN"Yes" RESET : BRIGHT_RED"No" RESET;
	out
		<< BRIGHT_WHITE " AForm      : " << BRIGHT_MAGENTA << src.getName() << RESET
		<< std::endl
		<< BRIGHT_WHITE " Signed     : " RESET << is_signed
		<< std::endl
		<< BRIGHT_WHITE " Sign grade : " RESET << src.getSignGrade()
		<< std::endl
		<< BRIGHT_WHITE " Exec grade : " RESET << src.getExecGrade()
		<< std::endl;
	return out;
}