#pragma once
#include <iostream>
#include <cmath>

class Fixed
{
  public:
	Fixed();
	Fixed(const Fixed &obj);
	Fixed(const int val);
	Fixed(const float val);
	~Fixed();

	Fixed &operator=(const Fixed &obj);

	bool operator>(const Fixed &obj) const;
	bool operator<(const Fixed &obj) const;
	bool operator>=(const Fixed &obj) const;
	bool operator<=(const Fixed &obj) const;
	bool operator==(const Fixed &obj) const;
	bool operator!=(const Fixed &obj) const;

	Fixed operator+(const Fixed &obj) const;
	Fixed operator-(const Fixed &obj) const;
	Fixed operator*(const Fixed &obj) const;
	Fixed operator/(const Fixed &obj) const;

	Fixed operator--(int); //int--
	Fixed& operator--();    //--int
	Fixed operator++(int); //int++
	Fixed& operator++();    //++int

	int getRawBits(void) const;

	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;
	static Fixed &min(Fixed &f1, Fixed &f2);
	static const Fixed &min(const Fixed &f1, const Fixed &f2);
	static Fixed &max(Fixed &f1, Fixed &f2);
	static const Fixed &max(const Fixed &f1, const Fixed &f2);

  private:
	int _raw;
	static const int _bits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &obj);
