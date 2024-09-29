/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 00:37:28 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/08/04 02:42:47 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
    *this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src) {
    if (this != &src) {
        _exchangeRate = src._exchangeRate;
    }
    return *this;
}

std::string  trim(const std::string& str) {
    std::string::size_type pos = str.find_first_not_of(' ');
    if (pos == std::string::npos) {
        return "";
    }
    std::string::size_type pos2 = str.find_last_not_of(' ');
    if (pos2 != std::string::npos) {
        return str.substr(pos, pos2 - pos + 1);
    }
    return str.substr(pos);

}

bool    isValidDate(const std::string &date) {

    std::string dt = trim(date);

    if (dt.length() != 10 || dt[4] != '-' || dt[7] != '-')
        return false;

    int year, month, day;
    std::istringstream iss(dt);
    char delim;

    iss >> year >> delim >> month >> delim >> day;
    
    if (iss.fail() || !iss.eof())
        return false;

    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    if (month == 2) {
        int maxDay = 28;

        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
            maxDay = 29;

        if (day > maxDay)
            return false;
    }

    if (month == 4 || month == 6 || month == 9 || month == 11)
        if (day > 30)
            return false;

    return true;
}

bool    isValidNumber(const std::string &number) {

    std::string num = trim(number);

    if (num[0] == '-') {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }

    for (size_t i = 0; i < num.length(); i++) {
        if (!isdigit(num[i]) && num[i] != '.') {
            std::cerr << "Error: Invalid number => " << num << std::endl;
            return false;
        }
    }

    double amount = atof(number.c_str());

    if (amount > 1000) {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    
    return true;
}

void BitcoinExchange::readCSV(const std::string &filename) {
    std::ifstream csv(filename.c_str());

    if (!csv)
        throw std::runtime_error("Error: can't read the file.");
    
    std::string header;
    getline(csv, header);
    
    std::string line;
    
    while (getline(csv, line)) {
        std::istringstream ss(line);
        std::string key, value;
        
        if (getline(ss, key, ',') && getline(ss, value, ',')) {
            _exchangeRate[key] = atof(value.c_str());
        } else {
            throw std::runtime_error("Error: invalid csv format.");
        }
    }

    csv.close();
}

float BitcoinExchange::getClosestExchangeRate(const std::string &date) const {
    std::string dt = trim(date);
    std::map<std::string, float>::const_iterator it = _exchangeRate.find(dt);
    
    if (it == _exchangeRate.end()) {
        it = _exchangeRate.lower_bound(dt);
        if (it != _exchangeRate.begin())
            --it;
    }

    return it->second;
}

void BitcoinExchange::processInputFile(const std::string &filename) {
    std::ifstream input(filename.c_str());

    if (!input)
        throw std::runtime_error("Error: could not open file.");

    std::string header;
    getline(input, header);

    if (header != "date | value")
        throw std::runtime_error("Error: invalid input file format.");

    std::string line;

    while (getline(input, line)) {
        std::istringstream ss(line);
        std::string date, amount;

        if (getline(ss, date, '|') && getline(ss, amount, '|')) {
            if (!isValidDate(date)) {
                std::cerr << "Error: Invalid date => " << date << std::endl;
                continue;
            }
            if (!isValidNumber(amount))
                continue;
            
            std::cout  << trim(date) << " => " << atof(amount.c_str()) << " = "  << atof(amount.c_str()) * getClosestExchangeRate(date) << std::endl;
        } else {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }

    input.close();
}

BitcoinExchange::~BitcoinExchange() {}