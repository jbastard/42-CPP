#include "../includes/Intern.hpp"
#include <cstdlib>
#include <ctime>

Intern::Intern()
{
    // std::cout << "Intern default constructor has been called" << std::endl;
}

Intern::Intern(const Intern& copy)
{
    // std::cout << "Intern copy constructor has been called" << std::endl;
    (void)copy;
}

Intern& Intern::operator=(const Intern& other)
{
    // std::cout << "Intern = operator overload has been called" << std::endl;
    (void)other;
    return (*this);
}

Intern::~Intern()
{
    // std::cout << "Intern destructor has been called" << std::endl;
}

AForm* Intern::createShrubbery(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPardon(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
    const FormArray forms[] = {
        {"Shrubbery Creation", createShrubbery},
        {"Presidential Pardon", createPardon},
        {"Robotomy Request", createRobotomy},
    };

    for (int i = 0; i < 3; ++i)
    {
        if (name == forms[i].formName)
        {
            std::cout << "Intern creates : " << name << std::endl;
            return forms[i].constructor(target);
        }
    }
    std::cerr << "Intern couldn't find any form named : " << name << " at least tell him to bring a coffee next time." << std::endl;
    return NULL;
}
