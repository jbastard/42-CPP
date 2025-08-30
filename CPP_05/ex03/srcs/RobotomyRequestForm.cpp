#include "../includes/RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), target(target) {
    // std::cout << "RobotomyRequestForm constructor has been called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy)
{
    this->target = copy.target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    // std::cout << "RobotomyRequestForm destructor has been called" << std::endl;
}

RobotomyRequestForm* RobotomyRequestForm::clone() const
{
    return new RobotomyRequestForm(*this);
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    if (!this->getSignedStatus())
        throw FormNotSignedException();
    if (executor.getGrade() > this->getExecGrade())
        throw GradeTooLowException();
    else
    {
        std::cout << "* bzzzzzzz bzzz drilling noise, fear for your brain bwww wwbw *" << std::endl;
        if (rand() % 2 == 0)
            std::cout << this->target << " has been robotomized." << std::endl;
        else
            std::cout << "Robotomy has failed for " << this->target << std::endl;
    }
}
