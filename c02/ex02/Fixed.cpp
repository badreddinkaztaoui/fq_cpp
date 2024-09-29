/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:27:35 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/02/15 05:56:20 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const Fixed &original) {
	*this = original;
}

Fixed::Fixed(const int value) {
	this->_value = value << this->_bits;
}

Fixed::Fixed(const float value) {
	this->_value = roundf(value * (1 << this->_bits));
}

Fixed &Fixed::operator=(const Fixed &original) {
	if (this != &original)
		this->_value = original.getRawBits();
	return *this;
}

Fixed::~Fixed() {}

int	Fixed::getRawBits(void) const {
	return this->_value;
}

void	Fixed::setRawBits(const int raw) {
	this->_value = raw;
}

float	Fixed::toFloat(void) const {
	return (this->_value / (float)(1 << this->_bits));
}

int	Fixed::toInt(void) const {
	return (this->_value >> this->_bits);
}

bool Fixed::operator>(const Fixed &original) const {
	return (this->_value > original.getRawBits());
}

bool Fixed::operator<(const Fixed &original) const {
	return (this->_value < original.getRawBits());
}

bool Fixed::operator>=(const Fixed &original) const {
	return (this->_value >= original.getRawBits());
}

bool Fixed::operator<=(const Fixed &original) const {
	return (this->_value <= original.getRawBits());
}

bool Fixed::operator==(const Fixed &original) const {
	return (this->_value == original.getRawBits());
}

bool Fixed::operator!=(const Fixed &original) const {
	return (this->_value != original.getRawBits());
}

Fixed Fixed::operator+(const Fixed &original) const {
	return Fixed(this->toFloat() + original.toFloat());
}

Fixed Fixed::operator-(const Fixed &original) const {
	return Fixed(this->toFloat() - original.toFloat());
}

Fixed Fixed::operator*(const Fixed &original) const {
	return Fixed(this->toFloat() * original.toFloat());
}

Fixed Fixed::operator/(const Fixed &original) const {
	return Fixed(this->toFloat() / original.toFloat());
}

Fixed &Fixed::operator++(void) {
	this->_value++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed &Fixed::operator--(void) {
	this->_value--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	operator--();
	return tmp;
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
	return ((f1.getRawBits() < f2.getRawBits()) ? f1 : f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
	return ((f1.getRawBits() > f2.getRawBits()) ? f1 : f2);
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
	return ((f1.getRawBits() < f2.getRawBits()) ? f1 : f2);
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
	return ((f1.getRawBits() > f2.getRawBits()) ? f1 : f2);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}