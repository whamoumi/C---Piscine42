#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <exception>
#include <cmath>
class Span{
	private:
		unsigned int _N;
		std::vector<int> span;
	public:
		Span(void){this->_N = 0;};
		Span(const Span &src){*this = src;};
		Span(unsigned int N){this->_N = N;};
		~Span(void){};
		class TabIsFull : public std::exception{
			const char* what() const throw(){
				return ("Le tableau est plein");
			}
		};
		class DistancetoShort : public std::exception{
			const char* what() const throw(){
				return ("distance trop courte entre deux nombres");
			}
		};
		void addNumber(unsigned int nbr){
			if(span.size() > this->_N)
				throw TabIsFull();
			else
				span.push_back(nbr);
		};
		int shortestSpan(void){
			if(span.size() <= 1)
				throw DistancetoShort();
			int min;
			std::vector<int>::iterator it = span.begin();
			std::vector<int>::iterator ite = span.end();
			std::vector<int>::iterator it2 = span.begin();
			std::vector<int>::iterator ite2 = span.end();
			min = *it - *(it + 1);
			for(; it != ite; it++)
			{
				it2 = (it + 1);
				ite2 = span.end();
				for(;it2 != ite2; it2++){
					if(min > abs(*it - *it2))
						min = abs(*it -*it2);
				}
			}
			return (min);
		};
	   	int longestSpan(void){
			if(span.size() <= 1)
				throw DistancetoShort();
			else
			{
				std::vector<int>::iterator it = span.begin();
				std::vector<int>::iterator ite = span.end();
				int min = *it;
				for(; it != ite; it++){
					if(*it < min)
						min = *it;
				}
				std::vector<int>::iterator it2 = span.begin();
				std::vector<int>::iterator ite2 = span.end();
				int max = *it2;
				for(; it2 != ite2; it2++){
					if(*it2 > max)
						max = *it2;
				}
				return(max - min);
			}
		};
};
#endif
