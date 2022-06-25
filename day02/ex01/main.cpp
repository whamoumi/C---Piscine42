#include "Zombie.hpp"
#include <iostream>
#include <string>

int main()
{
	Zombie *horde = zombieHorde(5, "wanis");
	delete [] horde;
	return (0);
}