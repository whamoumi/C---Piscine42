#include "ScavTrap.hpp"
ScavTrap::ScavTrap( void ){
	std::cout << "Constructeur par default de ScavTrap" << std::endl;
}

ScavTrap::ScavTrap( const std::string &name ){
	this->_name = name;
	this->Hit_points = 100;
	this->Energy_points = 50;
	this->Attack_damage = 20;
	std::cout << "Constructeur de ScavTrap" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &src ){
	*this = src;
	std::cout << "Constructeur par copie de ScavTrap" << std::endl;
}

void ScavTrap::attack( const std::string& target ){
	std::cout << "ScavTrap "<<_name <<" attacks "<< target << " , causing "<< Attack_damage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate( void ){
	std::cout << "ScavTrap " << _name << "is in Gate Keeper mode" << std::endl;
}

ScavTrap::~ScavTrap( void ){
	std::cout << "Destructeur de ScavTrap" << std::endl;
}

std::string ScavTrap::getName( void ) const{
	return _name;
}
int ScavTrap::getHit_point( void ) const{
	return Hit_points;
}
int ScavTrap::getEnergy_point( void ) const{
	return Energy_points;
}
int ScavTrap::getAttack_damage( void ) const{
	return Attack_damage;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &src){
	this->_name = src.getName();
	this->Hit_points = src.getHit_point();
	this->Energy_points = src.getEnergy_point();
	this->Attack_damage = src.getAttack_damage();
	return *this;
}
