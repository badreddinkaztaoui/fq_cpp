/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 06:07:12 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/08/09 04:56:55 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <stdexcept>
#include <climits>
#include <utility>


class PmergeMe {
private:
    std::vector<int> _v;
    std::deque<int> _d;
public:
    PmergeMe();
    PmergeMe(const PmergeMe &src);
    PmergeMe &operator=(const PmergeMe &src);
    ~PmergeMe();

    std::vector<int> & getV();
    std::deque<int> & getD();

    void    parseArgs(int ac, char **av);
    void    mergeVSort(std::vector<int> &v);
    void    mergeDSort(std::deque<int> &d);
    double  sortVector(std::vector<int> &v, bool _stdout);
    double  sortDeque(std::deque<int> &d, bool _stdout);
    void    printVector(std::vector<int> &v);
    void    printDeque(std::deque<int> &d);
};



#endif