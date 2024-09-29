/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 03:16:42 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/02/16 16:12:56 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
   ScavTrap s1("scav 1");
   ScavTrap s2(s1);
   ScavTrap s3 = s1;
   FragTrap f1("frag 1");
   FragTrap f2(f1);
   FragTrap f3 = f1;

   s1.attack("s2");
   s2.takeDamage(20);
   s2.beRepaired(10);
   s3.guardGate();
   f1.attack("f2");
   f2.takeDamage(20);
   f2.beRepaired(10);
   f3.highFivesGuys();

	return 0;
}