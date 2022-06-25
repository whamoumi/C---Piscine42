#include "Bureaucrat.hpp"

int main(void)
{
	//Bureaucrat wa("wanis", 0);
	//Bureaucrat wa1("wanis1", 155);
	Bureaucrat wa2("wanis2", 2);
	Form	a1("a1", 3, 3);
	Form	a2("a2", 1, 1);
	try {
		a1.beSigned(wa2);
		a2.beSigned(wa2);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	wa2.signForm(a1);
	wa2.signForm(a2);
}