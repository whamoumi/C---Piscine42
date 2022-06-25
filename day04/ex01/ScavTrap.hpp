#ifndef	SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"
class ScavTrap : public ClapTrap{
	public:
		ScavTrap( void );
		ScavTrap( const std::string &name );
		ScavTrap( const ScavTrap &src );
		void attack( const std::string& target );
		void guardGate( void );
		std::string getName( void ) const;
		int getHit_point( void ) const;
		int getEnergy_point( void ) const;
		int getAttack_damage( void ) const;
		ScavTrap &operator=(const ScavTrap &src);
		~ScavTrap( void );	
};

#endif
