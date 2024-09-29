/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:14:04 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/07/25 12:35:37 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Easyfind.hpp"

int main() {

    try {
        EasyFind<std::vector<int> > easyFind;
        std::vector<int> nums;

        for (int i = 0; i <= 10; i++) {
            nums.push_back(i);
        }
        
        easyFind.easyfind(nums, 12);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}