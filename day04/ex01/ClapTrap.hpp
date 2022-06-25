#ifndef	CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap{
	protected:
		std::string _name;
		int Hit_points;
		int Energy_points;
		int Attack_damage;
	public:
		ClapTrap( void );
		ClapTrap( const std::string &name );
		ClapTrap( const ClapTrap &src );
		void attack( const std::string& target );
		void takeDamage( unsigned int amount );
		void beRepaired( unsigned int amount );
		std::string getName( void ) const;
		int getHit_point( void ) const;
		int getEnergy_point( void ) const;
		int getAttack_damage( void ) const;
		ClapTrap &operator=(const ClapTrap &src);
		~ClapTrap( void );	
};
#endif