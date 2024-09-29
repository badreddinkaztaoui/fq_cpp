/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:43:22 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/02/18 19:56:26 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &original) {
	this->brain = new Brain(*original.brain);
	*this = original;
}

Cat &Cat::operator=(const Cat &original) {
	if (this != &original) {
		this->type = original.type;
		delete this->brain;
		this->brain = new Brain(*original.brain);
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
}

void Cat::makeSound() const {
	std::cout << "Me Ow" << std::endl;
}