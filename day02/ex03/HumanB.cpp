#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

HumanB::HumanB( std::string name )
{
	this->_name = name;
}

void HumanB::setWeapon( Weapon &arme )
{
	this->armee = &arme;
}
void	HumanB::attack( void )
{
	std::cout << this->_name << " attacks with his " << this->armee->getType() << std::endl;
}