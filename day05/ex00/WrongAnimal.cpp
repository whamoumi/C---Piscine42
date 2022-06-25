#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ){
	std::cout << "Constructeur de WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal &src ){
	*this = src;
	std::cout << "Constructeur par copie de WrongAnimal" << std::endl;
}

WrongAnimal::~WrongAnimal( void ){
	std::cout << "Destructeur de WrongAnimal" << std::endl;
}

void	WrongAnimal::makeSound( void ) const {
	std::cout << "Voici le bruit d'un WrongAnimal" << std::endl;
}


WrongCat::WrongCat( void ){
	type = "WrongCat";
	std::cout << "Constructeur de WrongCat" << std::endl;
}

WrongCat::WrongCat( const WrongCat &src ){
	*this = src;
	std::cout << "Constructeur par copie de WrongCat" << std::endl;
}

WrongCat::~WrongCat( void ){
	std::cout << "Destructeur de WrongCat" << std::endl;
}

void	WrongCat::makeSound( void ) const{
	std::cout << "Wrong MIAOU-MIAOU" << std::endl;
}

WrongCat		&WrongCat::operator=(const WrongCat &src){
	this->type = src.getType();
	return *this;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &src){
	this->type = src.getType();
	return *this;
}

std::string	WrongAnimal::getType( void ) const{
	return type;
}

std::string	WrongCat::getType( void ) const 
{
	return type;
}