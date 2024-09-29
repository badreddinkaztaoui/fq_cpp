/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:46:57 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/01/17 23:01:02 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>

typedef int (Contact::*Setter)(std::string);

class PhoneBook {
private:
	Contact	contacts[8];
	int		index;
public:
	PhoneBook();
	void	add(void);
	void	search(void);
	void	getContactInfo(std::string input, Setter setter);
	void	printContactsList(void);
	void	printContactInfo(int index);
};

#endif