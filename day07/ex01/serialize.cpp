#include <iostream>
typedef struct data{
}				Data;

uintptr_t serialize(Data* ptr)
{
	uintptr_t nbr = reinterpret_cast<uintptr_t>(ptr);
	return nbr;
}

Data* deserialize(uintptr_t raw)
{
	Data* data = reinterpret_cast<Data *>(raw);
	return data;
}

int main()
{
	Data wanis;
	uintptr_t nbr = serialize(&wanis);
	Data *waniss = deserialize(nbr);

	std::cout << &wanis << std::endl; 
	std::cout <<  waniss<< std::endl;
}