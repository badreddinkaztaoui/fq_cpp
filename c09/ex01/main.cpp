/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 02:47:14 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/08/04 04:11:19 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Usage: ./RPN \"[RPN expression]\"" << std::endl;
        return 1;
    }

    try {
        RPN rpn;
        rpn.fillStack(av[1]);
        rpn.calculate();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}