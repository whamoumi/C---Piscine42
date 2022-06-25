#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
int Bureaucrat::GetGrade(void) const
{
	return this->grade;
}

std::string Bureaucrat::GetName(void) const
{
	return this->name;
}

void Bureaucrat::incremente_grade( void )
{
	this->grade -= 1;
	if (this->grade < 1)
		throw GradeTooLowException();
}

void Bureaucrat::decremente_grade( void )
{
	this->grade += 1;
	if (this->grade > 150)
		throw GradeTooHighException();
}

std::ostream & operator<<(std::ostream & o , Bureaucrat const & rhs)
{
	o << "<" << rhs.GetName() << ">, bureaucrat grade <"<<  rhs.GetGrade() << ">";
	return o;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const &copy)
{
	this->name = copy.GetName();
	this->grade = copy.GetGrade();
	return *this;
}

std::string Form::GetName( void ) 
{
	return this->_name;
}

bool Form::GetSigned( void ) 
{
	return this->_signed;
}

int	Form::GetSignedgrade( void ){
	return this->_signedgrade;
}

int	Form::GetExecutegrade( void ){
	return this->_signedgrade;
}

Form::Form(std::string name , int signedgrade, int executegrade)
{
	this->_name = name;
	try
	{
		if (signedgrade < 1)
			throw GradeTooLowException();
		if (signedgrade > 150)
			throw GradeTooHighException();
		if (executegrade < 1)
			throw GradeTooLowException();
		if (executegrade > 150)
			throw GradeTooHighException();
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	this->_signedgrade = signedgrade;
	this->_executegrade = executegrade;
	this->_signed = false;
}

Form::Form( Form &copy)
{
	*this = copy;
}
Form & Form::operator=(Form &copy)
{
	this->_name = copy.GetName();
	this->_signed = copy.GetSigned();
	this->_executegrade = copy.GetExecutegrade();
	this->_signedgrade = copy.GetSignedgrade();
	return *this;
}

std::ostream & operator<<(std::ostream & o, Form & src)
{
	o << "Le formulaire de nom <" << src.GetName() <<"> il faut au moins le niveau <" << src.GetSignedgrade() <<">  pour le signer et voici son statut <"<< src.GetSigned() <<">" << std::endl;
	return o;
}

Form & Form::beSigned(Bureaucrat &a)
{
	if (a.GetGrade() <= this->_signedgrade)
		this->_signed = true;
	else
		throw GradeTooLowException();
	return *this;
}
//------------------------------------------------------------------

ShrubberyCreationForm::ShrubberyCreationForm( std::string name ): Form(name, 145, 137)
{
	this->_target = name;
	this->_grade_execution = 137;
	this->_grade_signature = 145;
}

RobotomyRequestForm::RobotomyRequestForm( std::string name ): Form(name, 45, 72)
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
		if (result % 2 == 0)
		{
			std::cout << "* PZZZZZZ PZZZZZ PZZZZZZZ * bruit de perceuse de " << executor.GetName() << std::endl;
			throw 2;
		}
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
PresidentialPardonForm::PresidentialPardonForm( std::string name ): Form(name, 5, 25)
{
	this->_target = name;
	this->_grade_execution = 25;
	this->_grade_signature = 5;
}
void PresidentialPardonForm::execute( Bureaucrat const &executor)
{
	if (executor.GetGrade() <= _grade_signature && executor.GetGrade() <= _grade_execution)
	{
		std::cout << "<" << executor.GetName() << "> a été pardonnée par Zafod Beeblebrox" << std::endl;
		throw 2;
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

int main()
{
	Bureaucrat a("wamis", 5);
	ShrubberyCreationForm wanis(" Shrubbery ");
	RobotomyRequestForm waniss(" Robotomy ");
	PresidentialPardonForm wanisss(" wanis ");
	try
	{
		wanis.execute(a);	
	}	
	catch(std::exception & e)
	{	
		std::cout << e.what();
	}
	catch(int i)
	{
		if (i == 1)
			a.executeForm(wanis);
	}
	try
	{
		waniss.execute(a);	
	}	
	catch(std::exception & e)
	{	
		std::cout << e.what();
	}
	catch(int i)
	{
		if (i == 2)
			a.executeForm(waniss);
	}
	try
	{
		wanisss.execute(a);	
	}	
	catch(std::exception & e)
	{	
		std::cout << e.what();
	}
	catch(int i)
	{
		if (i == 2)
			a.executeForm(wanisss);
	}
}