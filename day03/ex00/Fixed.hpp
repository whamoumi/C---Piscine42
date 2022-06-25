#ifndef _FIXED_HPP_
#define _FIXED_HPP_

#include <iostream>
#include <string>

class Fixed{
	private:
		int _fixed_point;
		static int _bits; 
	public:
		Fixed( void );
		Fixed( Fixed const & src);
		~Fixed( void );
		int getRawBits( void );
		void setRawBits(int const raw);
		Fixed & operator=( Fixed const & rhs);
};
#endif
