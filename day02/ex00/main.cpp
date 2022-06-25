#include "Zombie.hpp"
#include <iostream>
#include <string>

int main()
{
	Zombie *wanis = newZombie("newZombie");
	wanis->announce();
	delete wanis;
	return (0);
}