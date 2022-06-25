#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie* zombieHorde( int N, std::string name )
{
	if (N >= 1)
	{
		Zombie* zombiehorde = new Zombie[N];
		int i = 0;
		while (i < N)
		{
			zombiehorde[i].Setvariables(name);
			zombiehorde[i].announce();
			i++;
		}
		return(zombiehorde);
	}
	return(NULL);
}
