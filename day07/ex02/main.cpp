#include <iostream>
#include <random>
#include <exception>
#include "cast.hpp"
#include <ctime>
Base * generate( void )
{
	int nb = std::time(0) % 3;
	if (nb == 0)
	{
		Base *returned = new A();
		return returned;
	}
	else if (nb == 1)
	{	
		Base *returned = new B();
		return returned;
	}
	else
	{	
		Base *returned = new C();
		return returned;
	}

}

void	identify( Base *p )
{
	B* b = dynamic_cast<B*>(p);
	A* a = dynamic_cast<A*>(p);
	C* c = dynamic_cast<C*>(p);
	if (b != NULL)
		std::cout << "identify * B" << std::endl;
	if (a != NULL)
		std::cout << "identify * A" << std::endl;
	if (c != NULL)
		std::cout << "identify * C"  <<std::endl;
}

void identify( Base &p )
{
	try{
		B &b = dynamic_cast<B&>(p);
		std::cout << "identify & " << b.n << std::endl;
	}
	catch(std::bad_cast &e){
	}
	try{
		C &c = dynamic_cast<C&>(p);
		std::cout << "identify & " << c.n << std::endl;
	}
	catch(std::bad_cast &e){
	}
	try{
		A &a = dynamic_cast<A&>(p);
		std::cout << "identify & " << a.n << std::endl;
	}
	catch(std::bad_cast &e){
	}
}
int main()
{
	Base *base = generate();
	Base *basee = generate();
	Base *baseee = generate();
	Base *baseeee = generate();
	identify(base);
	identify(basee);
	identify(*base);
	identify(*basee);
	delete base;delete basee;delete baseee;delete baseeee;
}
