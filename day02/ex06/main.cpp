#include "Karen.hpp"

int main(int ac, char **av)
{
	Karen karen;

	if (ac == 2 && karen.find_good_number(av[1]) != 0)
	{	
		karen.complain(av[1]);
		return (0);
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	return (0);
}