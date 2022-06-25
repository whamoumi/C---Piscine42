#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;
class Form{
	private:
		std::string _name;
		bool		_signed;
		int			_signedGrade;
		int			_executeGrade;
	public:
		Form(const std::string &name, int signedGrade, int _executeGrade);
		Form( const Form &src );
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
		void	beSigned(const Bureaucrat &bureaucrat);
		bool	getSigned(void) const;
		std::string	getName(void) const;
		~Form( void );
};

//std::ostream	&operator<<(std::ostream &in, const Form &src);


#endif