#pragma once
#include <iostream>

class Bureaucrat;

class AForm {

private:
	const std::string	_name;
	bool 				_signed;
	int					_sign_grade;
	int					_exec_grade;

public:

	AForm();
	AForm(const std::string& name, int sign_grade, int exec_grade);
	AForm(const AForm &copy);
	virtual ~AForm();

	AForm &operator=(const AForm &src);

	const	std::string& getName() const;
	bool	isSigned() const;
	int		getSignGrade() const;
	int		getExecGrade() const;

	void	beSigned(const Bureaucrat& b);

	virtual void execute(const Bureaucrat& executor) const = 0;

	class	GradeTooHighException: public std::exception {
	public:
		virtual const char *what()const throw();
	};

	class	GradeTooLowException: public std::exception {
	public:
		virtual const char *what()const throw();
	};

	class	NotSignedException: public std::exception {
	public:
		virtual const char *what()const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const AForm &src);