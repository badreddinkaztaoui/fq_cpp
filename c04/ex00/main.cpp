/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:50:44 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/02/18 19:37:12 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongAnimal();


	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << wrongCat->getType() << std::endl;
	
	cat->makeSound();
	dog->makeSound();
	wrongCat->makeSound();
	animal->makeSound();
	wrongAnimal->makeSound();


	delete cat;
	delete dog;
	delete wrongCat;
	delete animal;
	delete wrongAnimal;

	return 0;
}