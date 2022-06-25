#ifndef _WEAPON_HPP_
#define _WEAPON_HPP_
#include <iostream>
#include <string>

class Weapon {
	public:
		Weapon(std::string arme );
		~Weapon( void );
		void setType( std::string String );
		std::string& getType();
		void announce( void );
	private:
		std::string _string;
};

#endif