/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:11:11 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/07/20 17:38:55 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Funcs.hpp"

int main() {

    Funcs<int> intFunc;

    int a = 2;
    int b = 3;
    intFunc.swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << intFunc.min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << intFunc.max( a, b ) << std::endl;

    Funcs<std::string> strFunc;
    std::string c = "chaine1";
    std::string d = "chaine2";
    
    strFunc.swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << strFunc.min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << strFunc.max( c, d ) << std::endl;
    return 0;
}