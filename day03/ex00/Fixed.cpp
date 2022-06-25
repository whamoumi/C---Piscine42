#include "Fixed.hpp"

int Fixed::_bits = 8;
Fixed::Fixed( void )
{
	this->_fixed_point = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed( void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void )
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixed_point;
	
}

void Fixed::setRawBits( int const raw )
{
	this->_fixed_point = raw;
}
Fixed & Fixed::operator=( Fixed const & rhs)
{
	this->_fixed_point = rhs._fixed_point;
	std::cout << "Assignation operator called" << std::endl;
	return *this;
}
