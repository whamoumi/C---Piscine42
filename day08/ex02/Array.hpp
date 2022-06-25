#ifndef _ARRAY_HPP_
#define _ARRAY_HPP_

#include <stdexcept>
#include <string>
#include <iostream>

template <typename T>

class Array{
	private :
		T * tab;
		unsigned int nb;
	public :
		Array( void ){this->tab = new T(); this->nb = 0;};
		Array( unsigned int n)
		{
			this->tab = new T[n];
			for(unsigned int i = 0; i < n; i++){
				tab[i] = 0;
			}
			this->nb = n;
		};
		Array( Array & src ){*this = src;};
		unsigned int getNb( void ){return this->nb;};
		T * getTab( void ){ return this->tab;};
		T & operator[](int i)
		{
			if (i < 0 || i >= (int)this->nb)
				throw outofrange();
			return this->tab[i];
		};
		~Array( void ){delete tab;};
		Array & operator=( Array & src )
		{
			this->nb = src.getNb();
			this->tab = new T[nb];
			for(unsigned int i = 0; i < nb; i++){
				tab[i] = src.tab[i];	
			}
			return *this;
		};
		unsigned int size(void)
		{
			return this->nb;
		}	
		class outofrange : public std::exception {
			public:
				const char* what() const throw()
				{
					return("OUT OF RANGE");
				}
		};

};	

#endif
