#include "Fixed.hpp"


int Fixed::_bits = 8;

Fixed::Fixed( void )
{
	this->_fixed_point = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const & src)
{
	*this = src;
	std::cout << "Copy constructor called"<< std::endl;
	return ;
}
Fixed::Fixed( int param )
{
	this->_fixed_point = param * 256 ;
	std::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed( float const param )
{
	this->_fixed_point = (roundf(param) * 256) + roundf((param - roundf(param)) * 256);
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed( void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	return _bits;
}

void Fixed::setRawBits( int const raw )
{
	this->_bits = raw;
}

float Fixed::toFloat( void ) const
{
	return (float)(this->_fixed_point / 256);
} 

Fixed & Fixed::operator=( Fixed const & rhs)
{
	this->_fixed_point = rhs._fixed_point;
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

std::ostream & operator<<(std::ostream &o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}
int Fixed::toInt(void) const 
{
	return (std::roundf(this->_fixed_point / 256));
}

