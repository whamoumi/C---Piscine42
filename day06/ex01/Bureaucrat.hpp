#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"
class Form;
class Bureaucrat{
	private:
		std::string _name;
		int _grade;
	public:
		Bureaucrat( void );
		Bureaucrat( const std::string &name, int grade );
		Bureaucrat( const Bureaucrat &src );
		class GradeTooHighExeption : public std::exception {
			const char* what() const throw(){
				return "Le grade est trop haut";
			}
		};
		class GradeTooLowExeption : public std::exception {
			const char* what() const throw(){
				return "Le grade est trop bas";
			}
		};
		std::string getName( void ) const ;
		int 		getGrade( void )const ;
		void	incrementGrade( void );
		void	decrementGrade( void );
		void	signForm( const Form &src );
		Bureaucrat &operator=(const Bureaucrat &src );
		~Bureaucrat( void );
};

std::ostream	&operator<<(std::ostream &in, const Bureaucrat &src);
#endif