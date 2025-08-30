#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm{
    private:
        std::string target;
        ShrubberyCreationForm();
    public:
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& copy);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        virtual ~ShrubberyCreationForm();
        virtual void execute(const Bureaucrat& executor) const;
        virtual ShrubberyCreationForm* clone() const;
};
