/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 03:55:35 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/07/18 11:18:15 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class ShrubberyCreationForm;
class PresidentialPardonForm;
class RobotomyRequestForm;

Intern::Intern() {}

Intern::Intern(Intern const & rhs) {
    *this = rhs;
}

Intern & Intern::operator=(Intern const & rhs) {
    if (this != &rhs) {
        *this = rhs;
    }
    return *this;
}

Intern::~Intern() {}

AForm * Intern::makeForm(std::string const name, std::string const target) {
    size_t i = 0;
	std::string form[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};

	for (i = 0; i < 3; i++)
	{
		if (form[i] == name)
			break;
	}
	switch (i)
	{
	case 0:
		std::cout << "Intern creates " << name << std::endl;
		return (new RobotomyRequestForm(target));
	case 1:
		std::cout << "Intern creates " << name << std::endl;
		return (new PresidentialPardonForm(target));
	case 2:
		std::cout << "Intern creates " << name << std::endl;
		return (new ShrubberyCreationForm(target));
	default:
		std::cout << "Intern can't create " << name << " because it's not a valid form" << std::endl;
		return (NULL);
	}
}
