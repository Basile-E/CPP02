#pragma once
#include <iostream>
#include <cmath>

class Fixed
{
	public :
		Fixed();
		Fixed(const Fixed& obj);
		Fixed(const int val);
		Fixed(const float val);
		~Fixed();

		Fixed &operator=(const Fixed& obj);

		int getRawBits( void ) const;

		void setRawBits( int const raw );

		float toFloat( void ) const;
		int toInt( void ) const;

	private :
		int _raw;
		static const int _bits = 8;
};

std::ostream &operator<<(std::ostream & out, const Fixed& obj);