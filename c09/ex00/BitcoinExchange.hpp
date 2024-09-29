/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:31:14 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/08/04 02:08:42 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_H
#define BITCOIN_EXCHANGE_H

#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <stdexcept>

class BitcoinExchange {
private:
    std::map<std::string, float> _exchangeRate;
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &src);
    BitcoinExchange &operator=(const BitcoinExchange &src);
    ~BitcoinExchange();
    
    void    readCSV(const std::string &filename);
    float   getClosestExchangeRate(const std::string &date) const;
    void    processInputFile(const std::string &filename);
};

bool            isValidDate(const std::string &date);
bool            isValidNumber(const std::string &number);
std::string     trim(const std::string& str);

#endif