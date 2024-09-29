/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 06:06:01 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/08/09 04:55:28 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av) {
    try {
        PmergeMe p;

        p.parseArgs(ac, av);
        double vtime = p.sortVector(p.getV(), true);
        double dtime = p.sortDeque(p.getD(), false);
        std::cout << "Time to process a range of " << p.getV().size() << " elements with std::vector : " << vtime << " s" << std::endl;
        std::cout << "Time to process a range of " << p.getD().size() << " elements with std::deque : " << dtime << " s" << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}