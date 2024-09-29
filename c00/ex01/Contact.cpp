/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:10:00 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/01/18 16:02:22 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// ------------------------------------ //
// ------------- Helpers -------------- //
// ------------------------------------ //

std::string trim(std::string str) {
	size_t first = str.find_first_not_of(' ');
	if (std::string::npos == first)
      return (str);
	size_t last = str.find_last_not_of(' ');
	return (str.substr(first, (last - first + 1)));
}

std::string	truncat(std::string str) {
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

// ------------------------------------ //
// ------------- Setters -------------- //
// ------------------------------------ //

int	Contact::setFirstName(std::string firstName) {
	firstName = trim(firstName);
	if (firstName.empty()) {
		std::cout << "\033[1;31m" << "First name can't be empty" << "\033[0m" << std::endl;
		return (1);
	} else {
		for (size_t i = 0; i < firstName.length(); i++) {
			if (!isalpha(firstName[i])) {
				std::cout << "\033[1;31m" << "First name must be alphabetic" << "\033[0m" << std::endl;
				return (1);
			}
		}
		this->firstName = firstName;
	}
	return (0);
}

int	Contact::setLastName(std::string lastName) {
	lastName = trim(lastName);
	if (lastName.empty()) {
		std::cout << "\033[1;31m" << "Last name can't be empty" << "\033[0m" << std::endl;
		return (1);
	} else {	
		for (size_t i = 0; i < lastName.length(); i++) {
			if (!isalpha(lastName[i])) {
				std::cout << "\033[1;31m" << "Last name must be alphabetic" << "\033[0m" << std::endl;
				return (1);
			}
		}
		this->lastName = lastName;
	}
	return (0);
}

int	Contact::setNickname(std::string nickname) {
	nickname = trim(nickname);
	if (nickname.empty()) {
		std::cout << "\033[1;31m" << "Nickname can't be empty" << "\033[0m" << std::endl;
		return (1);
	} else {
		for (size_t i = 0; i < nickname.length(); i++) {
			if (!isalnum(nickname[i])) {
				std::cout << "\033[1;31m" << "Nickname must be alphanumeric" << "\033[0m" << std::endl;
				return (1);
			}
		}
		this->nickname = nickname;
	}
	return (0);
}

int	Contact::setPhoneNumber(std::string phoneNumber) {
	phoneNumber = trim(phoneNumber);
	if (phoneNumber.empty()) {
		std::cout << "\033[1;31m" << "Phone number can't be empty" << "\033[0m" << std::endl;
		return (1);
	} else {
		for (size_t i = 0; i < phoneNumber.length(); i++) {
			if (!isdigit(phoneNumber[i])) {
				std::cout << "\033[1;31m" << "Phone number must be numeric" << "\033[0m" << std::endl;
				return (1);
			}
		}
		this->phoneNumber = phoneNumber;
	}
	return (0);
}

int	Contact::setDarkestSecret(std::string darkestSecret) {
	darkestSecret = trim(darkestSecret);
	if (darkestSecret.empty()) {
		std::cout << "\033[1;31m" << "Darkest secret can't be empty" << "\033[0m" << std::endl;
		return (1);
	} else {
		for (size_t i = 0; i < darkestSecret.length(); i++) {
			if (!isalnum(darkestSecret[i])) {
				std::cout << "\033[1;31m" << "Darkest secret must be alphanumeric" << "\033[0m" << std::endl;
				return (1);
			}
		}
		this->darkestSecret = darkestSecret;
	}
	return (0);
}

// ------------------------------------ //
// ------------- Getters -------------- //
// ------------------------------------ //

std::string	Contact::getFirstName(void) {
	return (this->firstName);
}

std::string	Contact::getLastName(void) {
	return (this->lastName);
}

std::string	Contact::getNickname(void) {
	return (this->nickname);
}

std::string	Contact::getPhoneNumber(void) {
	return (this->phoneNumber);
}

std::string	Contact::getDarkestSecret(void) {
	return (this->darkestSecret);
}

// ------------------------------------ //
// ------------- Methodes ------------- //
// ------------------------------------ //

void	Contact::printContact(int index) {
	std::cout << "|" << std::setw(10) << index << "|";
	std::cout << std::setw(10) << truncat(Contact::getFirstName()) << "|";
	std::cout << std::setw(10) << truncat(Contact::getLastName()) << "|";
	std::cout << std::setw(10) << truncat(Contact::getNickname()) << "|" << std::endl;
}

void	Contact::printContactInfo(void) {
	std::cout << "First name: " << Contact::getFirstName() << std::endl;
	std::cout << "Last name: " << Contact::getLastName() << std::endl;
	std::cout << "Nickname: " << Contact::getNickname() << std::endl;
	std::cout << "Phone number: " << Contact::getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << Contact::getDarkestSecret() << std::endl;
}