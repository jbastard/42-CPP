#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern{
    protected:
        typedef AForm* (*FormConstructor)(const std::string&);

        struct FormArray
        {
            std::string formName;
            FormConstructor constructor;
        };
        static AForm* createShrubbery(const std::string& target);
        static AForm* createPardon(const std::string& target);
        static AForm* createRobotomy(const std::string& target);
    public:
        Intern();
        Intern(const Intern& copy);
        Intern& operator=(const Intern& other);
        ~Intern();

        AForm* makeForm(const std::string& name, const std::string& target);
};
