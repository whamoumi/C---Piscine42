#ifndef _FIXED_HPP_
#define _FIXED_HPP_

#include <iostream>
#include <string>
#include <cmath>

class Fixed{
	private:
		float _fixed_point;
		static int _bits; 
	public:
		Fixed( void );
		Fixed( Fixed const & src);
		Fixed( int const param );
		Fixed( float const param );
		~Fixed( void );
		int getRawBits( void ) const ;
		void setRawBits(int const raw);
		int toInt( void ) const;
		float getvalue( void ) const;
		float toFloat( void ) const;
		Fixed & operator=( Fixed const & rhs);
};

std::ostream & operator<<(std::ostream &o, Fixed const & rhs);

#endif