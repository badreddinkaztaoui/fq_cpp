/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:58:56 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/07/19 21:18:04 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <exception>
#include <ctime>

class Base {
public:
    virtual ~Base() {};
};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif