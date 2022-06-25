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
		void execute( Bureaucrat const &executor );
		std::string GetName( void ) { return _target;};
		class GradeTooLowexecuteException : public std::exception {
			public:
				const char* what() const throw()
				{
					return("le grade est trop bas pour l'execution du formulaire");
				}
		};
};
/*
RobotomyRequestForm::RobotomyRequestForm( std::string name ): Form(name)
{
	this->_target = name;
	this->_grade_execution = 72;
	this->_grade_signature = 45;
}
void RobotomyRequestForm::execute( Bureaucrat const &executor)
{
	if (executor.GetGrade() <= _grade_signature && executor.GetGrade() <= _grade_execution)
	{
		std::time_t result = std::time(nullptr);
		std::cout << result "'fsdfdsfdsfds" << std::endl;
		throw 1;
	}
	else if (executor.GetGrade() > _grade_signature && executor.GetGrade() > _grade_execution)
	{
		throw GradeTooLowException();
		throw GradeTooLowexecuteException();
	}
	else if(executor.GetGrade() > _grade_signature && executor.GetGrade() < _grade_execution)
		throw GradeTooLowException();
	else if(executor.GetGrade() < _grade_signature && executor.GetGrade() > _grade_execution)
		throw GradeTooLowexecuteException();


}*/
#endif