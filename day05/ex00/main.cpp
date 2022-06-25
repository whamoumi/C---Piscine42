#include "Animal.hpp"
#include "WrongAnimal.hpp"

int main( void )
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	const WrongAnimal* e = new WrongCat();
	e->makeSound(); 
	delete j;
	delete i;
	delete e;
	delete meta;
	return 0;
}