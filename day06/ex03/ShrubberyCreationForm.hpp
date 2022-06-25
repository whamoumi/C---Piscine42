#ifndef _SHRUBBERYCREATIONFORM_HPP_
#define _SHRUBBERYCREATIONFORM_HPP_

#include <iostream>
#include <fstream>
#include <string>

#include "Form.hpp"
#include "Bureaucrat.hpp"


class ShrubberyCreationForm : public Form {
	private :
		std::string _target;
		int _grade_signature;
		int _grade_execution;
	public :
		ShrubberyCreationForm( std::string name );
		void execute( Bureaucrat const & executor );
		std::string GetName( void ) { return _target;};
};


#endif