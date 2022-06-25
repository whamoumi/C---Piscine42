#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ){
	this->Hit_points = 10;
	this->Energy_points = 10;
	this->Attack_damage = 0;
	std::cout << "Constructeur par default de ClapTrap" << std::endl;
}

ClapTrap::ClapTrap( const std::string &name ){
	this->_name = name;
	this->Hit_points = 10;
	this->Energy_points = 10;
	this->Attack_damage = 0;
	std::cout << "Constructeur de ClapTrap" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &src ){
	*this = src;
	std::cout << "Constructeur par copie de ClapTrap" << std::endl;
}

void ClapTrap::attack( const std::string& target ){
	std::cout << "ClapTrap "<<_name <<" attacks "<< target << " , causing "<< Attack_damage << " points of damage!" << std::endl;
}
void ClapTrap::takeDamage( unsigned int amount ){
	std::cout << "ClapTrap " << _name << " take " << amount << " damages" << std::endl;
}
void ClapTrap::beRepaired( unsigned int amount ){
	std::cout << "ClapTrap " << _name << " take " << amount << " points of life" << std::endl;
}
ClapTrap::~ClapTrap( void ){
	std::cout << "Destructeur de ClapTrap" << std::endl;
}

std::string ClapTrap::getName( void ) const{
	return _name;
}
int ClapTrap::getHit_point( void ) const{
	return Hit_points;
}
int ClapTrap::getEnergy_point( void ) const{
	return Energy_points;
}
int ClapTrap::getAttack_damage( void ) const{
	return Attack_damage;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &src){
	this->_name = src.getName();
	this->Hit_points = src.getHit_point();
	this->Energy_points = src.getEnergy_point();
	this->Attack_damage = src.getAttack_damage();
	return *this;
}