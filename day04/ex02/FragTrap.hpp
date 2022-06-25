#ifndef	SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"
class FragTrap : public ClapTrap{
	public:
		FragTrap( void );
		FragTrap( const std::string &name );
		FragTrap( const FragTrap &src );
		void attack( const std::string& target );
		void highFivesGuys(void);
		std::string getName( void ) const;
		int getHit_point( void ) const;
		int getEnergy_point( void ) const;
		int getAttack_damage( void ) const;
		FragTrap &operator=(const FragTrap &src);
		~FragTrap( void );	
};

#endif