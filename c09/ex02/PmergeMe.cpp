/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 06:08:20 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/08/09 04:56:49 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) {
    *this = src;
}

PmergeMe & PmergeMe::operator=(const PmergeMe &src) {
    if (this != &src) {
        this->_v = src._v;
        this->_d = src._d;
    }
    return *this;
}

std::vector<int> & PmergeMe::getV() {
    return this->_v;
}

std::deque<int> & PmergeMe::getD() {
    return this->_d;
}

void    PmergeMe::parseArgs(int ac, char **av) {
    if (ac < 2)
        throw std::invalid_argument("Usage: ./PmergeMe [args]");
    
    std::vector<int> _nums;

    for (int i = 1; i < ac; i++) {
        std::string arg = av[i];
        if (arg.empty() || arg.find_first_not_of("0123456789") != std::string::npos)
            throw std::invalid_argument("Error: Invalid argument");
        int num = std::atoi(arg.c_str());
        if (num < 0 || num >= INT_MAX)
            throw std::invalid_argument("Error: Invalid argument");
        _nums.push_back(num);

        if (std::count(_nums.begin(), _nums.end(), num) > 1)
            throw std::invalid_argument("Error: Duplicate argument");
        
        this->_v = _nums;
        this->_d = std::deque<int>(_nums.begin(), _nums.end());
    }
}

void    PmergeMe::mergeVSort(std::vector<int> &v) {
    if (v.size() <= 1)
        return;

    for (size_t i = 0; i < v.size() - 1; i += 2) {
        if (v[i] > v[i + 1]) {
            std::swap(v[i], v[i + 1]);
        }
    }

    if (v.size() > 2) {
        int mid = v.size() / 2;
        std::vector<int> left(v.begin(), v.begin() + mid);
        std::vector<int> right(v.begin() + mid, v.end());
        mergeVSort(left);
        mergeVSort(right);

        std::vector<int> tmp;
        std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(tmp));

        for (size_t i = 0; i < tmp.size() - 1; i += 2) {
            int second = tmp[i + 1];
            tmp.erase(tmp.begin() + i + 1);
            std::vector<int>::iterator it = std::lower_bound(tmp.begin(), tmp.end(), second);
            tmp.insert(it, second);            
        }

        v = tmp;
    }
}

void    PmergeMe::mergeDSort(std::deque<int> &d) {
    if (d.size() <= 1)
        return;

    for (size_t i = 0; i < d.size() - 1; i += 2) {
        if (d[i] > d[i + 1]) {
            std::swap(d[i], d[i + 1]);
        }
    }

    if (d.size() > 2) {
        int mid = d.size() / 2;
        std::deque<int> left(d.begin(), d.begin() + mid);
        std::deque<int> right(d.begin() + mid, d.end());
        mergeDSort(left);
        mergeDSort(right);

        std::deque<int> tmp;
        std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(tmp));

        for (size_t i = 0; i < tmp.size() - 1; i += 2) {
            int second = tmp[i + 1];
            tmp.erase(tmp.begin() + i + 1);
            std::deque<int>::iterator it = std::lower_bound(tmp.begin(), tmp.end(), second);
            tmp.insert(it, second);            
        }
        d = tmp;
    }
}

double   PmergeMe::sortVector(std::vector<int> &v, bool _stdout) {
    if (_stdout) {
        std::cout << "Before: ";
        printVector(v);
    }
    clock_t time = clock();
    mergeVSort(v);
    time = clock() - time;
    if (_stdout) {
        std::cout << "After: ";
        printVector(v);
    }
    return ((double)time / CLOCKS_PER_SEC);
}

double    PmergeMe::sortDeque(std::deque<int> &d, bool _stdout) {
    if (_stdout) {
        std::cout << "Before: ";
        printDeque(d);
    }
    clock_t time = clock();
    mergeDSort(d);
    time = clock() - time;
    if (_stdout) {
        std::cout << "After: ";
        printDeque(d);
    }
    return ((double)time / CLOCKS_PER_SEC);
}

void    PmergeMe::printVector(std::vector<int> &v) {
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

void    PmergeMe::printDeque(std::deque<int> &d) {
    for (size_t i = 0; i < d.size(); i++) {
        std::cout << d[i] << " ";
    }
    std::cout << std::endl;
}

PmergeMe::~PmergeMe() {}

