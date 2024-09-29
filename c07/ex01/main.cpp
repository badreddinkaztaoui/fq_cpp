/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:10:24 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/07/20 18:17:41 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

template <typename T>

void print(T const &x) {
    std::cout << x << std::endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
    Iter<int> iter;
    iter.iter(arr, sizeof(arr) / sizeof(arr[0]), print);
    Iter<char> iter2;
    iter2.iter(letters, sizeof(letters) / sizeof(letters[0]), print);
    return 0;
}