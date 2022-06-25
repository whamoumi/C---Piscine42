#ifndef _FORM_HPP_
#define _FORM_HPP_

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;

class Form{
	private :
		std::string _name;
		bool _signed;
		int	_signedgrade;
		int _executegrade; 
	public :
		std::string GetName( void );
		int	GetSignedgrade( void );
		int	GetExecutegrade( void );
		bool GetSigned( void );
		Form( std::string name , int signedgrade, int executegrade);
		Form( Form &copy);
		~Form( void ){};
		Form & operator=(Form &copy);
		Form & beSigned(Bureaucrat &a);
		virtual void execute( Bureaucrat const & executor) = 0;
		class GradeTooHighException : public std::exception {
			public :
				const char* what() const throw()
				{
					return ("le grade est trop haut pour le formulaire");
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw()
				{
					return("le grade est trop bas pour le formulaire");
				}
		};
};

std::ostream & operator<<(std::ostream & o, Form const & src);
#endif
