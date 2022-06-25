#include "Zombie.hpp"
#include <iostream>
#include <string>

void	randomChump( std::string name)
{
	Zombie* randomzombie = new Zombie;
	randomzombie->Setvariables(name);
	randomzombie->announce();
	return ;
}