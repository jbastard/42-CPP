#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm{
    private:
        std::string target;
        PresidentialPardonForm();
    public:
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& copy);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        virtual ~PresidentialPardonForm();
        virtual void execute(const Bureaucrat& executor) const;
        virtual PresidentialPardonForm* clone() const;
};