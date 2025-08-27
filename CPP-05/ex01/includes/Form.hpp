#pragma once
#include <iostream>

class Bureaucrat;

class Form {

private:
	const std::string	_name;
	bool 				_signed;
	int					_sign_grade;
	int					_exec_grade;

public:

	Form();
	Form(const std::string& name, int sign_grade, int exec_grade);
	Form(const Form &copy);
	~Form();

	Form &operator=(const Form &src);

	const	std::string& getName() const;
	bool	isSigned() const;
	int		getSignGrade() const;
	int		getExecGrade() const;

	void	beSigned(const Bureaucrat& b);

	class	GradeTooHighException: public std::exception {
	public:
		virtual const char *what()const throw();
	};

	class	GradeTooLowException: public std::exception {
	public:
		virtual const char *what()const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const Form &src);