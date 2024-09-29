/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:52:36 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/02/18 20:04:14 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
protected:
	std::string type;
public:
	Animal();
	Animal(const Animal &original);
	Animal &operator=(const Animal &original);
	virtual ~Animal();

	std::string getType() const;
	void setType(std::string type);
	virtual void makeSound() const = 0;
};

#endif