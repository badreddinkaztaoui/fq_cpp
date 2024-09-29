/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Funcs.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:14:11 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/07/20 17:34:51 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCS_HPP
#define FUNCS_HPP

#include <iostream>

template <typename T>

class Funcs {
public:
    Funcs() {};
    Funcs(const Funcs &src) { *this = src; };
    Funcs &operator=(const Funcs &src) { (void)src; return *this; };
    ~Funcs() {};
    
    void    swap(T &a, T &b) {
        T tmp = a;
        a = b;
        b = tmp;
    }
    
    T       min(T a, T b) {
        return (a < b) ? a : b;
    }
    
    T       max(T a, T b) {
        return (a > b) ? a : b;
    }
};


#endif