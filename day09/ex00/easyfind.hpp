#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <vector>
#include <iostream>
template <typename T>
void	easyfind(T &tab, int occurence)
{
	typename T::iterator it = tab.begin();
	typename T::iterator ite = tab.end();
	for(; it != ite; it++){
		if (*it == occurence)
		{
			std::cout << "il y'a une occurence" << std::endl;
			return ;
		}
	}
	std::cout << "il ni y'a pas d'occurence" << std::endl;
}
#endif
