#include <iostream>
#include <vector>


template<typename T>

void	fonction(T &a)
{
	std::cout << a << std::endl;
}

template<typename T>

void	iter(T *tab, unsigned int lenght, void(*ptr)(T&))
{	
	unsigned int i = 0;
	while (i < lenght)
	{
		ptr(tab[i]);
		i++;
	}
}

int main()
{
	int tab[5];
	int i = 0;
	while (i < 5)
	{
		tab[i] = i;
		i++;
	}
	iter<int>(tab, 5, fonction);
	char tabb[5];
	 i = 0;
	while (i < 5)
	{
		tabb[i] = i + 65;
		i++;
	}
	iter<char>(tabb, 5, fonction);
}
