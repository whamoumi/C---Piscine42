#include "Animal.hpp"
#include <vector>
int main()
{
	const Animal *e[20];
	for(int i = 0; i < 10; i++){
		if (i < 5)
			e[i] = new Cat();
		else
			e[i] = new Dog();
	}
	for(int i = 0; i < 10 ; i++){
		e[i]->makeSound();
	}
	for(int i = 0; i < 10 ; i++){
		delete e[i];
	}
	return 0;
}