/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 03:11:03 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/02/16 15:36:09 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "Default is created" << std::endl;
	this->_name = "Default";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name) {
	std::cout << name << " is created" << std::endl;
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap(ClapTrap const &original) {
	*this = original;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &original) {
	if (this != &original) {
		this->_name = original._name;
		this->_hitPoints = original._hitPoints;
		this->_energyPoints = original._energyPoints;
		this->_attackDamage = original._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << this->_name << " is destroyed" << std::endl;
}

void ClapTrap::attack(std::string const &target) {
	if (this->_energyPoints <= 0) {
		std::cout << this->_name << " has no energy points to attack!" << std::endl;
		return;
	} else {
		std::cout << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints -= 1;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (amount <= 0 || this->_hitPoints <= 0) {
		std::cout << this->_name << " has no hit points to take damage!" << std::endl;
		return;
	} else {
		std::cout << this->_name << " takes " << amount << " points of damage!" << std::endl;
		this->_hitPoints -= amount;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (amount <= 0 || this->_hitPoints >= 10) {
		std::cout << this->_name << " has no hit points to repair!" << std::endl;
		return;
	} else {
		std::cout << this->_name << " is repaired for " << amount << " points!" << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints -= 1;
	}
}