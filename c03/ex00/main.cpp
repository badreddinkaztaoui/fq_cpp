/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 03:16:42 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/02/16 03:18:58 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	ClapTrap a("a");
   ClapTrap b("b");
   ClapTrap c("c");

   b.takeDamage(5);
   a.attack("b");
   b.attack("a");
   a.takeDamage(5);
   
   a.beRepaired(10);
   b.beRepaired(10);
	return 0;
}