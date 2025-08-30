#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm{
    private:
        std::string target;
        RobotomyRequestForm();
    public:
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& copy);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        virtual ~RobotomyRequestForm();
        virtual void execute(const Bureaucrat& executor) const;
        virtual RobotomyRequestForm* clone() const;
};