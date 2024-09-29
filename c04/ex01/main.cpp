/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:50:44 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/02/18 20:01:25 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal	*animals[10];

	// Create 5 dogs
	for (int i = 0; i < 5; i++) {
		animals[i] = new Dog();
	}
	// Create 5 cats
	for (int i = 5; i < 10; i++) {
		animals[i] = new Cat();
	}
	
	// Make all animals makeSound
	for (int i = 0; i < 10; i++) {
		animals[i]->makeSound();
	}

	// Delete all animals
	for (int i = 0; i < 10; i++) {
		delete animals[i];
	}

	return 0;
}