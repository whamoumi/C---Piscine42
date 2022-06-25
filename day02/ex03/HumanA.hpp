#ifndef _HUMANA_HPP_
#define _HUMANA_HPP_
#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA {
	public:
		HumanA( std::string name, Weapon &arme);
		void setName( std::string name );
		void attack( void );
		~HumanA( void ){};
	private:
		Weapon &armee;
		std::string _name;	
};

#endif