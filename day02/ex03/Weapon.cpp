#include "Weapon.hpp"
#include "HumanA.hpp"


Weapon::Weapon( std::string random )
{
	setType(random);
}

Weapon::~Weapon( void )
{
}
void	Weapon::setType( std::string String )
{
	this->_string = String;
}
std::string& Weapon::getType()
{
	return (this->_string);
}

void	Weapon::announce()
{
	std::cout << (getType()) << std::endl;
}
