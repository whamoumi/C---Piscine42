#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie* newZombie( std::string name)
{
	Zombie* newzombie = new Zombie;
	newzombie->Setvariables(name);
	return (newzombie);
}