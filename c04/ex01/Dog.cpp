/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:32:22 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/02/18 19:56:55 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &original) {
	this->brain = new Brain(*original.brain);
	*this = original;
}

Dog &Dog::operator=(const Dog &original) {
	if (this != &original) {
		this->type = original.type;
		delete this->brain;
		this->brain = new Brain(*original.brain);
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}

void	Dog::makeSound() const {
	std::cout << "Woof Woof" << std::endl;
}


