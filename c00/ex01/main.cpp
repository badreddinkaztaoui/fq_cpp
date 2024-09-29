/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:33:22 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/01/17 15:30:14 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int	main(void)
{
	std::string	cmd;
	PhoneBook	phoneBook;

	while (1) {
		std::cout << "Command: ";
		if (!std::getline(std::cin, cmd))
			break ;
		if (cmd.empty()) {
			continue ;
		} else
		if (cmd == "EXIT") {
			break ;
		} else if (cmd == "ADD") {
			phoneBook.add();
		} else if (cmd == "SEARCH") {
			phoneBook.search();
		} else {
			std::cout << "\033[1;31m" << "Invalid Command ❌" << "\033[0m" << std::endl;
		}
	}
	return (0);
}