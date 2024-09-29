/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:51:06 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/01/16 15:30:49 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void	struppr(int ac, char **av) {
	int i = 1;

	while (i < ac)
	{
		for (int j = 0; av[i][j]; j++)
			std::cout << (char)std::toupper(av[i][j]);
		i++;
	}
	std::cout << std::endl;
}

int main(int ac, char **av)
{
	if (ac == 1)
		  std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		struppr(ac, av);
	return (0);
}