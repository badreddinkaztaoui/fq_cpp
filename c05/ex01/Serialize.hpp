/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:37:57 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/07/19 16:55:24 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <iostream>
#include <string>
#include <stdint.h>

struct Data {
    std::string s1;
    std::string s2;
    int num;
};

class Serialize {
    private:
        Serialize();
        Serialize(const Serialize &src);
        Serialize &operator=(const Serialize &src);
        ~Serialize();
    public:
        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);
};

#endif