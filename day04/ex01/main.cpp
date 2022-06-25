#include "ScavTrap.hpp"

int main( void )
{
	ScavTrap A("wanis");
	ScavTrap B;
	B = A;
	B.attack("la cible");
	B.takeDamage( 10 );
	B.beRepaired( 10 );
	return 0;
}