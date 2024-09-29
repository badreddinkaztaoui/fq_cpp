/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:43:17 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/07/25 18:40:17 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
#define SPAN_H

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <climits>

class Span {
private:
    unsigned int _n;
    std::vector<int> _span;
public:
    Span();
    Span(unsigned int n);
    Span(Span const &origin);
    Span &operator=(Span const &origin);
    ~Span();

    void addNumber(int number);
    void fillSpan(int range);
    int  shortestSpan();
    int  longestSpan();
};

#endif