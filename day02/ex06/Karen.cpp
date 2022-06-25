#include "Karen.hpp"

Karen::Karen( void )
{
	this->level[0] = "DEBUG";	
	this->level[1] = "INFO";	
	this->level[2] = "WARNING";	
	this->level[3] = "ERROR";	
}

void	Karen::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void	Karen::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void	Karen::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void	Karen::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

int 	Karen::find_good_number( std::string level )
{
	int i = 0;

	while (i < 4)
	{
		if (this->level[i] == level)
			return (i + 1);
		i++;
	}
	return (0);
}

void	Karen::complain( std::string level )
{
	int i = find_good_number(level);
	switch (i)
		{
			case 1 : debug() ; std::cout << std::endl;
			case 2 : info(); std::cout << std::endl;
			case 3 : warning(); std::cout << std::endl;
			case 4 : error(); std::cout << std::endl;
			default: break;
		}
}
