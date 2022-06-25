#include <iostream>
#include <string>

int main( void )
{
	std::string STRING = "HI THIS IS BRAIN";
	std::string *stringPTR = &STRING;
	std::string &stringREF = STRING;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
}