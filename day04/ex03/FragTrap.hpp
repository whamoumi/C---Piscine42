#ifndef	FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap{
	private:
		std::string _name;
		int Hit_points;
		int Energy_points;
		int Attack_damage;
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