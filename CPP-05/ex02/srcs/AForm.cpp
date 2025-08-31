#include "../includes/AForm.hpp"

AForm::AForm() : name("Default AForm"), minimumExecGrade(1), minimumSigningGrade(1)
{
	// std::cout << "Default AForm constructor has been called" << std::endl;
}

AForm::~AForm()
{
	// std::cout << "AForm destructor has been called" << std::endl;
}

AForm::AForm(const std::string& name, const int minimumSigningGrade, const int minimumExecGrade) : name(name), minimumExecGrade(minimumExecGrade), minimumSigningGrade(minimumSigningGrade)
{
	// std::cout << "AForm parametized constructor has been called" << std::endl;
	if (minimumSigningGrade < 1 || minimumExecGrade < 1)
		throw GradeTooHighException();
	else if (minimumSigningGrade > 150 || minimumExecGrade > 150)
		throw GradeTooLowException();
	this->is_signed = false;
}

AForm::AForm(const AForm& copy) : name(copy.name), minimumExecGrade(copy.minimumExecGrade), minimumSigningGrade(copy.minimumSigningGrade)
{
	// std::cout << "AForm copy constructor has been called" << std::endl;
	this->is_signed = copy.is_signed;
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		this->is_signed = other.is_signed;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << "AForm name -> " << form.getName() << std::endl << "AForm Minimum Signing Grade -> " << form.getSigningGrade() << std::endl << "AForm Minimum Exec Grade -> " << form.getExecGrade() << std::endl;
	return os;
}

const std::string AForm::getName() const
{
	return this->name;
}

bool AForm::getSignedStatus() const
{
	return this->is_signed;
}

int AForm::getSigningGrade() const
{
	return this->minimumSigningGrade;
}

int AForm::getExecGrade() const
{
	return this->minimumExecGrade;
}

const char * AForm::GradeTooHighException::what() const throw()
{
	return "Bureaucrat grade is too high";
}

const char * AForm::GradeTooLowException::what() const throw()
{
	return "Bureaucrat grade is too low";
}

const char* AForm::AlreadySignedException::what() const throw()
{
	return "Form is already signed why would you sign it again ?";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}

void AForm::beSigned(const Bureaucrat& crat)
{
	// std::cout << "Calling beSigned() method in AForm" << std::endl;
	int cratGrade = crat.getGrade();
	if (cratGrade > this->minimumSigningGrade)
		throw GradeTooLowException();
	else if (this->is_signed == true)
		throw AlreadySignedException();
	else
		this->is_signed = true;
}
