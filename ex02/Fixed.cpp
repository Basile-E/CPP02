#include "Fixed.hpp"

Fixed::Fixed()
{
	//std::cout << "Default constructor called" << std::endl;
	_raw = 0;
}

Fixed::Fixed(const Fixed &obj)
{
	//std::cout << "Copy constructor called" << std::endl;
	this->_raw = obj.getRawBits();
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int val)
{
	//std::cout << "Int constructor called" << std::endl;
	_raw = val << _bits;
	//std::cout << val << std::endl;
}

Fixed::Fixed(const float val)
{
	//std::cout << "Float constructor called" << std::endl;
	_raw = roundf(val * (1 << _bits));
}

//basically the most usefull copy operator overload EVER, peak engineering
Fixed &Fixed::operator=(const Fixed &obj)
{
	//std::cout << "Copy assignement operator called" << std::endl;
	if (this != &obj)
		_raw = obj.getRawBits();
	return (*this);
}

// the list :

bool Fixed::operator>(const Fixed &obj) const
{
	return (this->getRawBits() > obj.getRawBits());
}

bool Fixed::operator<(const Fixed &obj) const
{
	return (this->getRawBits() < obj.getRawBits());
}

bool Fixed::operator>=(const Fixed &obj) const
{
	return (this->getRawBits() >= obj.getRawBits());
}

bool Fixed::operator<=(const Fixed &obj) const
{
	return (this->getRawBits() <= obj.getRawBits());
}

bool Fixed::operator==(const Fixed &obj) const
{
	return (this->getRawBits() == obj.getRawBits());
}

bool Fixed::operator!=(const Fixed &obj) const
{
	return (!(*this == obj));
}

Fixed Fixed::operator+(const Fixed &obj) const
{
	Fixed res;
	res.setRawBits(this->_raw + obj._raw);
	return (res);
}

Fixed Fixed::operator-(const Fixed &obj) const
{
	Fixed res;
	res.setRawBits(this->_raw - obj._raw);
	return (res);
}

Fixed Fixed::operator*(const Fixed &obj) const
{
	Fixed res;
	long temp = (static_cast<long>(this->_raw)
			* static_cast<long>(obj._raw)) >> _bits;
	res.setRawBits(static_cast<int>(temp));
	return (res);
}

Fixed Fixed::operator/(const Fixed &obj) const
{
	Fixed res;
	if (obj._raw == 0)
	{
		std::cerr << "you think outside the box, I like it" << std::endl;
		return (res);
	}
	long temp = (static_cast<long>(this->_raw) << _bits)
		/ static_cast<long>(obj._raw);
	res.setRawBits(static_cast<int>(temp));
	return (res);
}

Fixed Fixed::operator--(int) //int-
{
	Fixed temp = *this;
	--_raw;
	return (temp);
}

Fixed& Fixed::operator--() //--in
{
	--_raw;
	return (*this);
}

Fixed Fixed::operator++(int) //int+
{
	Fixed temp = *this;
	++_raw;
	return (temp);
}

Fixed& Fixed::operator++() //++in
{
	++_raw;
	return (*this);
}

// the end of the list

std::ostream &operator<<(std::ostream &out, const Fixed &obj)
{
	//std::cout << "Insertion assignement operator called" << std::endl;
	out << obj.toFloat();
	return (out);
}

int Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (_raw);
}

void Fixed::setRawBits(int const raw)
{
	_raw = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(_raw) / (1 << _bits));
}

int Fixed::toInt(void) const
{
	return (_raw >> _bits);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
	return ((f1 < f2) ? f1 : f2);
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
	return ((f1 < f2) ? f1 : f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
	return ((f1 > f2) ? f1 : f2);
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
	return ((f1 > f2) ? f1 : f2);
}
