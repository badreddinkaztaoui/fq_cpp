/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:21:01 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/07/20 18:50:49 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdexcept>

template<typename T>

class Array {
private:
    T *_arr;
    unsigned int _size;
public:
    Array() {
        _arr = new T[0];
        _size = 0;
    };

    Array(unsigned int n) {
        _arr = new T[n];
        _size = n;
        for (unsigned int i = 0; i < n; i++)
            _arr[i] = 0;
    };

    Array(const Array &src) {
        _arr = new T[src._size];
        _size = src._size;
        for (unsigned int i = 0; i < _size; i++)
            _arr[i] = src._arr[i];
    };

    Array &operator=(const Array &src) {
        if (this == &src)
            return *this;
        delete [] _arr;
        _arr = new T[src._size];
        _size = src._size;
        for (unsigned int i = 0; i < _size; i++)
            _arr[i] = src._arr[i];
        return *this;
    };

    T &operator[](unsigned int i) {
        if (i >= _size)
            throw std::out_of_range("Index out of range");
        return _arr[i];
    };

    ~Array() {
        delete [] _arr;
    };

    unsigned int size() const {
        return _size;
    };
};

#endif