#ifndef _BUREAUCRAT_HPP_
#define _BUREAUCRAT_HPP_

#include <stdexcept>
#include <string>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat {
	private :
		std::string name;
		int grade;
	public :
		Bureaucrat( std::string name, int graade){
			this->name = name;
			try
			{
				if (graade < 1)
					throw GradeTooLowException();
				if (graade > 150)
					throw GradeTooHighException();
			}
			catch(std::exception & e)
			{
				std::cout << e.what() << std::endl;
			}
			this->grade = graade;

		};
		Bureaucrat( Bureaucrat const &copy){ *this = copy;};
		~Bureaucrat( void ){};
		std::string GetName(void) const;
		Bureaucrat & operator=(Bureaucrat const &copy);
		void signForm( bool a, std::string namee);
		void incremente_grade(void);
		void decremente_grade(void);
		int GetGrade(void) const ;
		void	executeForm(Form &form);
		class GradeTooHighException : public std::exception {
			public :
				const char* what() const throw()
				{
					return ("le grade depasse 150");
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw()
				{
					return("le grade est trop bas");
				}
		};
};

void Bureaucrat::signForm( bool a, std::string namee)
{
	if (a == 1)
		std::cout << "<"<< GetName() <<"> signs <"<< namee << ">" << std::endl;
	if (a == 0 )
		std::cout << "<"<< GetName() <<"> cannot sign because < Le niveau est trop bas>" << std::endl;
}

void	Bureaucrat::executeForm(Form &form)
{
	std::cout << "<"<< name <<"> executs <"<< form.GetName() << ">" << std::endl;	
}
std::ostream & operator<<(std::ostream & o , Bureaucrat const & rhs);
#endif