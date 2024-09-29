/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:45:24 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/02/18 19:49:42 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "Thoughts!";
}

Brain::Brain(const std::string type) {
	std::cout << "Brain constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = type;
}

Brain::Brain(const Brain &original) {
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = original.ideas[i];
}

Brain &Brain::operator=(const Brain &original) {
	std::cout << "Brain assignation operator called" << std::endl;
	if (this == &original)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->ideas[i] = original.ideas[i];
	return (*this);
}

Brain::~Brain() { std::cout << "Brain destructor called" << std::endl; }