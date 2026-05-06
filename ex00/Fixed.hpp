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
