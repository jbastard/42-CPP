#include "../includes/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {
    // std::cout << "ShrubberyCreationForm constructor has been called" << std::endl; 
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy)
{
    this->target = copy.target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    // std::cout << "ShrubberyCreationForm destructor has been called" << std::endl;
}

ShrubberyCreationForm* ShrubberyCreationForm::clone() const
{
    return new ShrubberyCreationForm(*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    if (!this->getSignedStatus())
        throw FormNotSignedException();
    if (executor.getGrade() > this->getExecGrade())
        throw GradeTooLowException();

    std::ofstream file((this->target + "_shrubbery").c_str());
    file << "      &&& &&  & &&\n";
    file << "   && &\\/&\\|& ()|/ @, &&\n";
    file << "   &\\/(/&/&||/& /_/)_&/_&\n";
    file << " &() &\\/&|()|/&\\/ '%\" & ()\n";
    file << " &_\\_&&_\\ |& |&&/&__%_/_& &&\n";
    file << "&&   && & &| &| /& & % ()& /&&\n";
    file << " ()&_---()&\\&\\|&&-&&--%---()~\n";
    file << "     &&     \\|||\n";
    file << "             |||\n";
    file << "             |||\n";
    file << "             |||\n";
    file << "       , -=-~  .-^- _\n";
    file.close();
}