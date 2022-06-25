#include "Form.hpp"

bool	Form::getSigned(void) const {
	return _signed;
}

std::string Form::getName( void ) const {
	return _name;
}

Form::Form(const std::string &name, int signedGrade, int executeGrade){
	_name = name;
	try{
		if(signedGrade < 1)
			throw GradeTooLowExeption();
		if(signedGrade > 150)
			throw GradeTooHighExeption();
		if(executeGrade < 1)
			throw GradeTooLowExeption();
		if(executeGrade > 150)
			throw GradeTooHighExeption();
	}catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	_signedGrade = signedGrade;
	_executeGrade = executeGrade;
	std::cout << "Constructeur de Form" << std::endl;
}

Form::Form( const Form &src ){
	*this = src;
	std::cout << "Constructeur par copie de Form" << std::endl;
}

void	Form::beSigned(const Bureaucrat &bureaucrat){
	if (bureaucrat.getGrade() < _signedGrade)
		_signed = true;
	else
	{
		_signed = false;
		throw GradeTooLowExeption();	
	}
}

Form::~Form( void ){
	std::cout << "Destructeur de Form" << std::endl;
}