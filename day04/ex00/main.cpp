#include "ClapTrap.hpp"

int main( void )
{
	ClapTrap A("wanis");
	A.attack("la cible");
	A.takeDamage( 10 );
	A.beRepaired( 10 );
	return 0;
}
