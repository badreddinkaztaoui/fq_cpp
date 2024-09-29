/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:51:24 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/07/25 18:44:14 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

static int min(int a, int b) {
    if (a < b)
        return (a);
    return (b);
}

Span::Span(): _n(0) {}

Span::Span(unsigned int n): _n(n) {}

Span::Span(Span const &origin) {
    *this = origin;
}

Span & Span::operator=(Span const &origin) {
    if (this != &origin) {    
        this->_n = origin._n;
        this->_span = origin._span;
    }
    return (*this);
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (this->_span.size() >= this->_n)
        throw std::runtime_error("Span is full");
    this->_span.push_back(number);
}

void Span::fillSpan(int range) {
    for (int i = 0; i < range; i++) {
        this->addNumber(rand());
    }
}

int Span::shortestSpan() {
    if (this->_span.size() < 2)
        throw std::runtime_error("No span can be found.");
    int minNum = INT_MAX;
    
    std::vector<int> tmp = this->_span;
    std::sort(tmp.begin(), tmp.end());
    
    for (int i = 1; i < (int)tmp.size(); i++) {
        minNum = min(minNum, tmp[i] - tmp[i - 1]);
    }
    
    return (minNum);
}

int Span::longestSpan() {
    if (this->_span.size() < 2)
        throw std::runtime_error("No span can be found.");
    std::vector<int> tmp = this->_span;
    std::sort(tmp.begin(), tmp.end());
    return (tmp[tmp.size() - 1] - tmp[0]);
}