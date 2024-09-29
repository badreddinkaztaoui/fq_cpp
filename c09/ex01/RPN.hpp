/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 02:46:39 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/08/04 05:01:06 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <cmath>
#include <stdexcept>
#include <algorithm>

class RPN {
private:
    std::stack<int> _stack;
public:
    RPN();
    RPN(const RPN &src);
    RPN &operator=(const RPN &src);
    ~RPN();

    void    fillStack(const std::string &str);
    void    calculate();
};

bool    isValidInput(const std::string &str);

#endif


