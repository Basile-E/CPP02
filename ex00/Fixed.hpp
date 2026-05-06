#pragma once
#include <iostream>

class Fixed
{
	public :
		Fixed();
		Fixed(Fixed& obj);
		~Fixed();

		Fixed &operator=(const Fixed& obj);

		int getRawBits( void ) const;

		void setRawBits( int const raw );

	private :
		int _raw;
		static const int _bits = 8;
};

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_raw = 0;
}

Fixed::Fixed(Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_raw = obj.getRawBits();
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

//basically the most usefull copy operator overload EVER, peak engineering 
Fixed& Fixed::operator=(const Fixed& obj)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &obj)
		_raw = obj.getRawBits();
	return (*this);
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
