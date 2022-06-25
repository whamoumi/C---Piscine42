#ifndef _HUMANB_HPP_
#define _HUMANB_HPP_
#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB {
	public:
		HumanB( std::string name );
		void setWeapon( Weapon &arme );
		void attack( void );
		~HumanB( void ){};
	private:
		Weapon* armee;
		std::string _name;	
};

#endif