/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:14:23 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/07/25 12:35:20 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <vector>

template <typename T>

class EasyFind {
public:
    EasyFind() {}
    EasyFind(const EasyFind &easyfind) {
        *this = easyfind;
    }
    EasyFind &operator=(const EasyFind &easyfind) {
        (void)easyfind;
        return *this;
    }
    ~EasyFind() {}

    void easyfind(T &container, int value) {

        int isExist = true;

        typename T::iterator it;
        for (it = container.begin(); it < container.end(); it++) {
            if (*it == value) {
                std::cout << *it << std::endl;
                isExist = false;
            }
        }
        if (isExist)
            throw std::runtime_error("Not Found");
    }
};



#endif