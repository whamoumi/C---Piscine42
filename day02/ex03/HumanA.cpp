#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

HumanA::HumanA( std::string name, Weapon &arme) : armee(arme)
{
	setName(name);

}
void	HumanA::setName( std::string  name )
{
	this->_name = name;
}

void	HumanA::attack( void )
{
	std::cout << this->_name << " attacks with his " << this->armee.getType() << std::endl;
}
