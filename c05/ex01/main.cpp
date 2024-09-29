/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:24:15 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/07/19 15:19:41 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

int main() {

    Data *data = new Data;

    data->s1 = "Hello";
    data->s2 = "World";
    data->num = 42;

    uintptr_t raw = Serialize::serialize(data);
    Data *data2 = Serialize::deserialize(raw);

    std::cout << "Data 1: " << data->s1 << " " << data->s2 << " " << data->num << std::endl;
    std::cout << "Raw: " << raw << std::endl;
    std::cout << "Data 2: " << data2->s1 << " " << data2->s2 << " " << data2->num << std::endl;
    
    delete data;

    return (0);
}