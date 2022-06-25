#include "Bureaucrat.hpp"

int main(void)
{
	//Bureaucrat wa("wanis", 0);
	//Bureaucrat wa1("wanis1", 155);
	Bureaucrat wa2("wanis2", 1);
	std::cout << wa2;
	try{
		wa2.decrementGrade();
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
}