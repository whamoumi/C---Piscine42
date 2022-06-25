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

Dog::Dog( void ){
	type = "Dog";
	brain = new Brain();
	std::cout << "Constructeur de Dog" << std::endl;
}

Dog::Dog( const Dog &src ){
	*this = src;
	std::cout << "Constructeur par copie de Dog" << std::endl;
}

Dog::~Dog( void ){
	delete brain;
	std::cout << "Destructeur de Dog" << std::endl;
}

void	Dog::makeSound( void ) const {
	std::cout << "WOUF-WOUF" << std::endl;
}

Cat::Cat( void ){
	type = "Cat";
	brain = new Brain();
	std::cout << "Constructeur de Cat" << std::endl;
}

Cat::Cat( const Cat &src ){
	*this = src;
	std::cout << "Constructeur par copie de Cat" << std::endl;
}

Cat::~Cat( void ){
	delete brain;
	std::cout << "Destructeur de Cat" << std::endl;
}

void	Cat::makeSound( void ) const{
	std::cout << "MIAOU-MIAOU" << std::endl;
}

Brain::Brain( void ){
	std::cout << "Constructeur de Brain" << std::endl;
}

Brain::Brain( const Brain &src ){
	*this = src;
	std::cout << "Constructeur par copie de Brain" << std::endl;
}

Brain::~Brain( void ){
	std::cout << "Destructeur de Brain" << std::endl;
}

Dog &Dog::operator=(const Dog &src){
	this->type = src.getType();
	std::cout << "operateur de copie de Dog" << std::endl;
	return *this;
}

Animal &Animal::operator=(const Animal &src){
	this->type = src.getType();
	std::cout << "operateur de copie de Animal" << std::endl;
	return *this;
}

Cat &Cat::operator=(const Cat &src){
	this->type = src.getType();
	std::cout << "operateur de copie de Cat" << std::endl;
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

