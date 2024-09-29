/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:55:35 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/01/18 16:02:44 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// ------------------------------------ //
// ------------- Helpers -------------- //
// ------------------------------------ //

void	printHeader(void) {
	std::cout << "|-------------------------------------------|" << std::endl;
   std::cout << "|                   PhoneBook               |" << std::endl;
   std::cout << "|-------------------------------------------|" << std::endl;
   std::cout << "|  index   |first name|last name | nickname |" << std::endl;
   std::cout << "|----------|----------|----------|----------|" << std::endl;
}

void	printFooter(void) {
	std::cout << "|-------------------------------------------|" << std::endl;
}

void	printMsg(std::string msg, int flag) {
	if (flag == 0)
		std::cout << "\033[1;32m" << msg << "\033[0m" << std::endl;
	else if (flag == 1)
		std::cout << "\033[1;31m" << msg << "\033[0m" << std::endl;
	else
		std::cout << msg << std::endl;
}

// ------------------------------------ //
// ------------- Methods -------------- //
// ------------------------------------ //

PhoneBook::PhoneBook() {
	this->index = 0;
}

void	PhoneBook::getContactInfo(std::string prompt, Setter setter) {
	std::string	input;
	int	status = 0;

	while (std::cin.good() && (input.empty() || status == 1)) {
		status = 0;
		std::cout << prompt;
		std::getline(std::cin, input);
		if ((this->contacts[this->index % 8].*setter)(input)) {
			status = 1;
		}
	}
	input.clear();
}

void	PhoneBook::add() {
	getContactInfo("Enter your firstname: ", &Contact::setFirstName);
	getContactInfo("Enter your lastname: ", &Contact::setLastName);
	getContactInfo("Enter your nickname: ", &Contact::setNickname);
	getContactInfo("Enter your phone number: ", &Contact::setPhoneNumber);
	getContactInfo("Enter your darkest secret: ", &Contact::setDarkestSecret);
	this->index++;
	printMsg("Contact added successfully ✔️", 0);
}

void	PhoneBook::printContactsList() {
	printHeader();
	for (int i = 0; i < this->index; i++) {
		if (i < 8) {
			this->contacts[i].printContact(i);
		}
	}
	printFooter();
}

void	PhoneBook::printContactInfo(int index) {
	std::string	input;
	std::cout << "Enter index: ";
	std::getline(std::cin, input);

	if (input.length() > 1 || input[0] < '0' || input[0] > '7') {
		printMsg("Invalid index ❌", 1);
		return ;
	} else if (input[0] - '0' >= index) {
		printMsg("Contact not found ❌", 1);
		return ;
	} else {
		this->contacts[input[0] - '0'].printContactInfo();
	}
}

void	PhoneBook::search() {
	std::string	input;

	if (this->index == 0) {
		printMsg("No contacts to show ℹ️", 1);
		return ;
	}
	printContactsList();
	printContactInfo(this->index);
}