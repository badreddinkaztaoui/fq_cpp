/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 03:16:42 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/02/16 15:44:29 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
   ScavTrap s1("scav 1");
   ScavTrap s2(s1);
   
   s1.attack("target");
   s1.takeDamage(10);
   s1.beRepaired(10);
   s1.guardGate();;
	return 0;
}