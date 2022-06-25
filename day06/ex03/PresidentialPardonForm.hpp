#ifndef _PRESIDENTIALPARDONFORM_HPP_
#define _PRESIDENTIALPARDONFORM_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "Form.hpp"
#include "Bureaucrat.hpp"


class PresidentialPardonForm : public Form {
	private :
		std::string _target;
		int _grade_signature;
		int _grade_execution;
	public :
		PresidentialPardonForm( std::string name );
		void execute( Bureaucrat const & executor );
		std::string GetName( void ) { return _target;};
		class GradeTooLowexecuteException : public std::exception {
			public:
				const char* what() const throw()
				{
					return("le grade est trop bas pour l'execution du formulaire");
				}
		};
};

#endif