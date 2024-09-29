/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:23:28 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/02/15 05:54:02 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
	int _value;
	static const int _bits = 8;
public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &original);
	Fixed &operator=(const Fixed &original);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(const int raw);
	float toFloat(void) const;
	int toInt(void) const;

	bool operator>(const Fixed &original) const;
	bool operator<(const Fixed &original) const;
	bool operator>=(const Fixed &original) const;
	bool operator<=(const Fixed &original) const;
	bool operator==(const Fixed &original) const;
	bool operator!=(const Fixed &original) const;

	Fixed operator+(const Fixed &original) const;
	Fixed operator-(const Fixed &original) const;
	Fixed operator*(const Fixed &original) const;
	Fixed operator/(const Fixed &original) const;

	Fixed &operator++(void);
	Fixed operator++(int);
	Fixed &operator--(void);
	Fixed operator--(int);

	static Fixed &min(Fixed &f1, Fixed &f2);
	static Fixed &max(Fixed &f1, Fixed &f2);
	static const Fixed &min(const Fixed &f1, const Fixed &f2);
	static const Fixed &max(const Fixed &f1, const Fixed &f2);
};


std::ostream &operator<<(std::ostream &out, const Fixed &fixed);


#endif