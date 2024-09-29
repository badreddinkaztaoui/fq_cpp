/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:40:51 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/07/20 18:19:47 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>

class Iter {
public:
    Iter() {};
    Iter(const Iter &src) { *this = src; };
    Iter &operator=(const Iter &src) { (void)src; return *this; };
    ~Iter() {};

    void    iter(T *arr, int len, void (*func)(T const &)) {
        for (int i = 0; i < len; i++) {
            func(arr[i]);
        }
    }
};

#endif