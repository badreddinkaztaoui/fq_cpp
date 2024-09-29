/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:33:53 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/07/19 21:26:50 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
    srand(time(NULL));
    int random = rand() % 3;
    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else
        return new C();
}

void    identify(Base *p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "Type of class p is: A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "Type of class p is: B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "Type of class p is: C" << std::endl;
    } else {
        std::cout << "Unknown type of class" << std::endl;
    }
}

void    identify(Base &p) {
    try {
        A &a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        (void)a;
    } catch (std::exception &e) {
        try {
            B &b = dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
            (void)b;
        } catch (std::exception &e) {
            try {
                C &c = dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
                (void)c;
            } catch (std::exception &e) {
                std::cerr << "Unkown type: " << e.what() << std::endl;
            }
        }
    }
}