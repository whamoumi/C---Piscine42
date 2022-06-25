#include "Animal.hpp"

Animal::Animal( void ){
	std::cout << "Constructeur de Animal" << std::endl;
}

Animal::Animal( const Animal &src ){
	*this = src;
	std::cout << "Constructeur par copie de Animal" << std::endl;
}

Animal::~Animal( void ){
	std::cout << "Destructeur de Animal" << std::endl;
}

void	Animal::makeSound( void ) const {
	std::cout << "Voici le bruit d'un animal" << std::endl;
}

Dog::Dog( void ){
	type = "Dog";
	std::cout << "Constructeur de Dog" << std::endl;
}

Dog::Dog( const Dog &src ){
	*this = src;
	std::cout << "Constructeur par copie de Dog" << std::endl;
}

Dog::~Dog( void ){
	std::cout << "Destructeur de Dog" << std::endl;
}

void	Dog::makeSound( void ) const {
	std::cout << "WOUF-WOUF" << std::endl;
}

Cat::Cat( void ){
	type = "Cat";
	std::cout << "Constructeur de Cat" << std::endl;
}

Cat::Cat( const Cat &src ){
	*this = src;
	std::cout << "Constructeur par copie de Cat" << std::endl;
}

Cat::~Cat( void ){
	std::cout << "Destructeur de Cat" << std::endl;
}

void	Cat::makeSound( void ) const{
	std::cout << "MIAOU-MIAOU" << std::endl;
}

Cat		&Cat::operator=(const Cat &src){
	this->type = src.getType();
	return *this;
}

Dog		&Dog::operator=(const Dog &src){
	this->type = src.getType();
	return *this;
}

Animal	&Animal::operator=(const Animal &src){
	this->type = src.getType();
	return *this;
}

std::string	Animal::getType( void ) const{
	return type;
}

std::string	Cat::getType( void ) const 
{
	return type;
}

std::string	Dog::getType( void ) const
{
	return type;
}
