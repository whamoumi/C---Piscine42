#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>
template <typename T>
class MutantStack : public std::stack<T>{
	public:
		MutantStack(void){};
		MutantStack(const MutantStack &src){*this =src;};
		virtual ~MutantStack(void){};
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin(void){
			return this->c.begin();
		};

		iterator end(void){
			return this->c.end();
		};
}; 

#endif
