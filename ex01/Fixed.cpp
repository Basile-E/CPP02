#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_raw = 0;
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_raw = obj.getRawBits();
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int val)
{
	std::cout << "Int constructor called" << std::endl;
	_raw = val << _bits;
	//std::cout << val << std::endl;
}

Fixed::Fixed(const float val)
{
	std::cout << "Float constructor called" << std::endl;
	_raw = roundf(val * (1 << _bits));
}

//basically the most usefull copy operator overload EVER, peak engineering 
Fixed& Fixed::operator=(const Fixed& obj)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &obj)
		_raw = obj.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream& out, const Fixed& obj)
{
	//std::cout << "Insertion assignement operator called" << std::endl;
	out << obj.toFloat();
	return (out);
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_raw);
}

void Fixed::setRawBits( int const raw )
{
	_raw = raw;
}

float Fixed::toFloat( void ) const
{
	return(static_cast <float>(_raw) / (1 << _bits));
}

int Fixed::toInt( void ) const
{
	return(_raw >> _bits);
}
