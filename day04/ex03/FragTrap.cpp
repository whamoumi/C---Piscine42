#include "FragTrap.hpp"
FragTrap::FragTrap( void ){
	this->Hit_points = 100;
	this->Energy_points = 100;
	this->Attack_damage = 30;
	std::cout << "Constructeur par default de FragTrap" << std::endl;
}

FragTrap::FragTrap( const std::string &name ){
	this->_name = name;
	this->Hit_points = 100;
	this->Energy_points = 100;
	this->Attack_damage = 30;
	std::cout << "Constructeur de FragTrap" << std::endl;
}

FragTrap::FragTrap( const FragTrap &src ){
	*this = src;
	std::cout << "Constructeur par copie de FragTrap" << std::endl;
}

void FragTrap::attack( const std::string& target ){
	std::cout << "FragTrap "<<_name <<" attacks "<< target << " , causing "<< Attack_damage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void){
	std::cout << "Do you want a high fives" << std::endl;
}

FragTrap::~FragTrap( void ){
	std::cout << "Destructeur de FragTrap" << std::endl;
}

std::string FragTrap::getName( void ) const{
	return _name;
}
int FragTrap::getHit_point( void ) const{
	return Hit_points;
}
int FragTrap::getEnergy_point( void ) const{
	return Energy_points;
}
int FragTrap::getAttack_damage( void ) const{
	return Attack_damage;
}
FragTrap &FragTrap::operator=(const FragTrap &src){
	this->_name = src.getName();
	this->Hit_points = src.getHit_point();
	this->Energy_points = src.getEnergy_point();
	this->Attack_damage = src.getAttack_damage();
	return *this;
}