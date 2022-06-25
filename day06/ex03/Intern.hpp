#ifndef _INTERN_HPP_
#define _INTERN_HPP_
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	public :
	Form * (*tab[3])(std::string);
	Intern(void){};
	Intern(Intern const &src){*this = src;};
	Intern &operator=(Intern const &src){

	};
	static Form * Robotomy(std::string element);
	static Form * Presidential(std::string element);
	static Form * Shrubbery(std::string element);
	Form * makeForm(std::string const element, std::string target)
	{
		std::string tabn[3];
		tabn[0] = "Presidential";
		tabn[1] = "Shrubbery";
		tabn[2] = "Robotomy";
		int i = 0;
		int count = 4;
		tab[0]=&Presidential;
		tab[1]=&Shrubbery;
		tab[2]=&Robotomy;
		while(i < 3)
		{
			if(element == tabn[i])
				count = i;
			i++;
		}
		if (count >= 0 && count < 3)
		{
			std::cout << "Intern creates <" << element << ">" << std::endl;
			return(tab[count])(target);
		}
		else
		{
			std::cout << "Le formulaire" << element <<" n'est pas connu" << std::endl;
			return 0;
		}
	};
};

Form * Intern::Robotomy(std::string element)
{
	Form *str = new RobotomyRequestForm(element);
	return str;
}

Form * Intern::Shrubbery(std::string element)
{
	Form *str = new ShrubberyCreationForm(element);
	return str;
}

Form * Intern::Presidential(std::string element)
{
	Form *str = new PresidentialPardonForm(element);
	return str;
}

#endif