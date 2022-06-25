#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ){
	std::cout << "Constructeur par default de DiamondTrap" << std::endl;
}

DiamondTrap::DiamondTrap( const std::string &name ): ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name"){
	this->_name = ClapTrap::getName();
	this->Hit_points = FragTrap::getHit_point();
	this->Energy_points = ScavTrap::getEnergy_point();
	this->Attack_damage = FragTrap::getAttack_damage();
	std::cout << "Constructeur de DiamondTrap" << std::endl;
}

void DiamondTrap::whoAmI( void ){
	std::cout << "Je suis le DiamondTrap " << _name << " " << Hit_points << " " << Energy_points << " " << Attack_damage << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap &src ){
	*this = src;
	std::cout << "Constructeur par copie de DiamondTrap" << std::endl;
}

DiamondTrap::~DiamondTrap( void ){
	std::cout << "Destructeur de DiamondTrap" << std::endl;
}

void DiamondTrap::attack(const std::string &target){
	ScavTrap::attack(target);
}

std::string DiamondTrap::getName( void ) const{
	return _name;
}

int DiamondTrap::getHit_point( void ) const{
	return Hit_points;
}

int DiamondTrap::getEnergy_point( void ) const{
	return Energy_points;
}

int DiamondTrap::getAttack_damage( void ) const{
	return Attack_damage;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src){
	this->_name = src.getName();
	this->Hit_points = src.getHit_point();
	this->Energy_points = src.getEnergy_point();
	this->Attack_damage = src.getAttack_damage();
	return *this;
}