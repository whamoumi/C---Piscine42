#include "Zombie.hpp"
#include <iostream>
#include <string>


void Zombie::announce( void )
{
	std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::Setvariables(std::string name)
{
	_name = name;
}
Zombie::~Zombie( void )
{
	std::cout << "it's the destructor of " << this->_name << std::endl;
}