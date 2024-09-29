/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:44:17 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/08/04 02:17:37 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
    
    if (ac < 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    
    try {
        BitcoinExchange btc;

        btc.readCSV("./data.csv");
        btc.processInputFile(av[1]);
        
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}