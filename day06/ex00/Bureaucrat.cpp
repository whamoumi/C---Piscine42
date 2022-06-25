#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ){
	std::cout << "Constructeur par defaut de Bureaucrat" << std::endl;
}

Bureaucrat::Bureaucrat( const std::string &name, int grade ){
	this->_name = name;
	try{
		if (grade < 1 )
			throw GradeTooLowExeption();
		if (grade > 150)
			throw GradeTooHighExeption();
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	this->_grade = grade;
	std::cout << "Constructeur de Bureaucrat" << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat &src ){
	*this = src;
	std::cout << "Constructeur par copie de Bureaucrat" << std::endl;
}

Bureaucrat::~Bureaucrat( void ){
	std::cout << "Destructeur par defaut de Bureaucrat" << std::endl;
}
std::ostream	&operator<<(std::ostream &in, const Bureaucrat &src){
	in << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
	return in;
}

std::string Bureaucrat::getName( void ) const {
	return _name;
}

int Bureaucrat::getGrade( void )const {
	return _grade;
}

void	Bureaucrat::decrementGrade( void ){
	_grade -= 1;
	if (_grade < 1 )
		throw GradeTooLowExeption();
}
void	Bureaucrat::incrementGrade( void ){
	_grade++;
	if (_grade > 150 )
		throw GradeTooHighExeption();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src ){
	this->_name = src.getName();
	this->_grade = src.getGrade();
	return *this;
}