#include "Fixed.hpp"


int Fixed::_bits = 8;

Fixed::Fixed( void )
{
	this->_fixed_point = 0;
}

Fixed::Fixed( Fixed const & src)
{
	*this = src;
	return ;
}
Fixed::Fixed( int param )
{
	this->_fixed_point = param  * 256 ;
}
Fixed::Fixed( float const param )
{
	this->_fixed_point = (roundf(param) * 256) + roundf((param - roundf(param)) * 256);
}

Fixed::~Fixed( void)
{
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
	return *this;
}

std::ostream & operator<<(std::ostream &o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}
Fixed  Fixed::operator+( Fixed const & rhs) const
{
	return Fixed(this->toFloat() + rhs.toFloat());

}

Fixed  Fixed::operator-( Fixed const & rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat());

}

Fixed  Fixed::operator*( Fixed const & rhs) const
{
		return Fixed(toFloat() * rhs.toFloat());

}

Fixed  Fixed::operator/( Fixed const & rhs) const
{
		return Fixed(this->_fixed_point / rhs.toFloat());
}

bool Fixed::operator==(Fixed const & rhs) const
{
	if (this->_fixed_point == rhs.toFloat())
		return true;
	else 
		return false;
}

bool Fixed::operator>=(Fixed const & rhs) const
{
		if (this->_fixed_point >= rhs.toFloat())
			return true;
		else 
			return false;
}

bool Fixed::operator<=(Fixed const & rhs) const
{
	if (this->_fixed_point <= rhs.toFloat())
		return true;
	else 
		return false;
}

bool Fixed::operator>(Fixed const & rhs) const
{
	if (this->_fixed_point > rhs.toFloat())
		return true;
	else 
		return false;
}

bool Fixed::operator<(Fixed const & rhs) const
{
	if (this->_fixed_point < rhs.toFloat())
		return true;
	else 
		return false;
}

bool Fixed::operator!=(Fixed const & rhs) const
{
	if (this->_fixed_point != rhs.toFloat())
		return true;
	else 
		return false;
}

Fixed const &	Fixed::max(Fixed const &rhs, Fixed const &ohs)
{
	if (rhs.toFloat() < ohs.toFloat())
		return ohs;
	else
		return rhs;
}

Fixed const &	Fixed::min(Fixed const &rhs, Fixed const &ohs)
{
	if (rhs.toFloat() < ohs.toFloat())
		return rhs;
	else
		return ohs;
}
int Fixed::toInt(void) const 
{
	return (std::roundf(this->_fixed_point / 256));
}

Fixed  Fixed::operator--(int )
{
	Fixed temp = *this;
	--temp._fixed_point;
   return temp;
}

Fixed & Fixed::operator--(void)
{
	this->_fixed_point--;
   return *this;
}

Fixed  Fixed::operator++(int )
{
	Fixed temp = *this;
	++*this;
	return temp;
}

Fixed & Fixed::operator++( void )
{
	this->_fixed_point++;
    return *this;
};