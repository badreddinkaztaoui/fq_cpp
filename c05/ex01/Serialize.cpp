/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:38:09 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/07/19 16:55:03 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

Serialize::Serialize() {}

Serialize::Serialize(const Serialize &src) {
    *this = src;
}

Serialize &Serialize::operator=(const Serialize &src) {
    (void)src;
    return (*this);
}

Serialize::~Serialize() {}

uintptr_t Serialize::serialize(Data *ptr) {
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serialize::deserialize(uintptr_t raw) {
    return (reinterpret_cast<Data *>(raw));
}
