/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:54:10 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/02/18 16:38:46 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	this->type = "Animal";
	std::cout << "Default animal constructor called" << std::endl;
}

Animal::Animal(const Animal &src) {
	*this = src;
}

Animal &Animal::operator=(const Animal &src) {
	if (this != &src)
		this->type = src.type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Default animal destructor called" << std::endl;
}

std::string Animal::getType() const {
	return this->type;
}

void Animal::setType(std::string type) {
	this->type = type;
}

void Animal::makeSound() const {
	std::cout << "Default animal sound" << std::endl;
}