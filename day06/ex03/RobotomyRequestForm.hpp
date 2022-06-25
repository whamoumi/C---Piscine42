#ifndef _ROBOTOMYREQUESTFORM_HPP_
#define _ROBOTOMYREQUESTFORM_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "Form.hpp"
#include "Bureaucrat.hpp"


class RobotomyRequestForm : public Form {
	private :
		std::string _target;
		int _grade_signature;
		int _grade_execution;
	public :
		RobotomyRequestForm( std::string name );
		void execute( Bureaucrat const & executor );
		std::string GetName( void ) { return _target;};
};
#endif