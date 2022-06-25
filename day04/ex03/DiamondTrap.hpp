#ifndef DIAMONTRAP_HPP
#define DIAMONTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "string"

class DiamondTrap : virtual public ScavTrap, virtual public FragTrap{
	private:
		std::string _name;
		int Hit_points;
		int Energy_points;
		int Attack_damage;
	public:
	    DiamondTrap( void );
		DiamondTrap( const std::string &name);
		DiamondTrap( const DiamondTrap &src);
		void	whoAmI( void );
		void attack(const std::string& target);
		std::string getName( void ) const;
		int getHit_point( void ) const;
		int getEnergy_point( void ) const;
		int getAttack_damage( void ) const;
		DiamondTrap &operator=(const DiamondTrap &src);
		~DiamondTrap( void );
};

#endif