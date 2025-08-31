#pragma once
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
	private:
		const		std::string name;
		bool		is_signed;
		const int	minimumExecGrade;
		const int	minimumSigningGrade;
		Form();

	public:
		~Form();
		Form(const std::string& name, const int minimumSigningGrade, const int minimumExecGrade);
		Form(const Form& copy);
		Form& operator=(const Form& other);

		const	std::string getName() const;
		bool	getSignedStatus() const;
		int		getSigningGrade() const;
		int		getExecGrade() const;

		void	beSigned(const Bureaucrat& crat);

		class GradeTooHighException : public std::exception{
			public:
				const char * what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				const char * what() const throw();
		};
		class AlreadySignedException : public std::exception{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& form);
