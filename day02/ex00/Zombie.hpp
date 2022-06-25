#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie{
	public:
		void announce( void );
		Zombie( void ){};
		~Zombie( void );
		void	Setvariables(std::string name);
		
	private:
		std::string _name;
};

void randomChump( std::string name );
Zombie* newZombie( std::string name );

#endif