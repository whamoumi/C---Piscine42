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

void ShrubberyCreationForm::execute( Bureaucrat const &executor)
{
	if (executor.GetGrade() <= _grade_signature && executor.GetGrade() <= _grade_execution)
	{
		std::ofstream	ofs(executor.GetName() +"_shrubbery");
		ofs<<"	    ccee88oo          "<< std::endl;
		ofs<<"  C8O8O8Q8PoOb o8oo     "<< std::endl;
		ofs<<"	dOB69QO8PdUOpugoO9bD  "<< std::endl;
		ofs<<" CgggbU8OU qOp qOdoUOdcb"<< std::endl;
		ofs<<"   o6OuU  /p u gcoUodpP "<< std::endl;
		ofs<<"       ||||||||            "<< std::endl;
		ofs<<"         |||||          "<< std::endl;
		ofs<<"         |||||          "<< std::endl;
		ofs<<"         |||||          "<< std::endl;
		ofs<<"        |||||||         "<< std::endl;
		ofs<<"       |||||||||        "<< std::endl;
		ofs.close();
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


}
#endif