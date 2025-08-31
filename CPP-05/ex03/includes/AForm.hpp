#pragma once
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
	private:
		const std::string name;
		bool is_signed;
		const int minimumExecGrade;
		const int minimumSigningGrade;
		AForm();
	public:
		virtual ~AForm();
		AForm(const std::string& name, const int minimumSigningGrade, const int minimumExecGrade);
		AForm(const AForm& copy);
		AForm& operator=(const AForm& other);
		virtual AForm* clone() const = 0;
		const std::string getName() const;
		bool getSignedStatus() const;
		int getSigningGrade() const;
		int getExecGrade() const;
		void beSigned(const Bureaucrat& crat);
		virtual void execute(const Bureaucrat& executor) const = 0;
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
		class FormNotSignedException : public std::exception{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& form);
