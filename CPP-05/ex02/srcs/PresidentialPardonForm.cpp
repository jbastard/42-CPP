#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), target(target) {
    // std::cout << "PresidentialPardonForm constructor has been called" << std::endl; 
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy)
{
    this->target = copy.target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    // std::cout << "PresidentialPardonForm destructor has been called" << std::endl;
}

PresidentialPardonForm* PresidentialPardonForm::clone() const
{
    return new PresidentialPardonForm(*this);
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    if (!this->getSignedStatus())
        throw FormNotSignedException();
    if (executor.getGrade() > this->getExecGrade())
        throw GradeTooLowException();
    else
        std::cout << this->target << " has been pardoned by Zaphod Beeblebox." << std::endl;
}