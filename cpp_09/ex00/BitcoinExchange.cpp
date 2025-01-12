/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 14:19:32 by mlegendr          #+#    #+#             */
/*   Updated: 2024/12/25 14:19:32 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "Default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copyCo)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copyCo;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copyOp)
{
	if (this == &copyOp)
		return *this;
	_exchangeRate = copyOp._exchangeRate;
	std::cout << "Assignement constructor called" << std::endl;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "Destructor called" << std::endl;
}

void BitcoinExchange::_addExchangeRateAndDatesToMap()
{
	const std::string fileName = "data.csv";
	std::ifstream data(fileName.c_str());
	if (!data.is_open())
		throw NoFileError();
	
	std::string input;
	std::getline(data, input);
	if (input != "date,exchange_rate")
		throw InvalidDataFormatError();
	
	while (std::getline(data, input))
	{
		std::string date = input.substr(0, input.find(','));
		std::string rate = input.substr(input.find(',') + 1);

		if (date.empty() || rate.empty() || !_validateDate(date) || !_validateExchangeRate(rate))
			throw InvalidDataFormatError();

		if (_exchangeRate.find(date) != _exchangeRate.end())
			throw MissingDataError();

		_exchangeRate[date] = std::strtod(rate.c_str(), NULL);

	}
}

bool BitcoinExchange::_validateDate(const std::string &date) const
{
	if (date.size() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	for (size_t i = 0; i < date.size(); i++)
	{
		if (i == 4 || i == 7)
            continue;
        if (date[i] < '0' || date[i] > '9')
            return false;
	}
	return true;
}

bool BitcoinExchange::_validateExchangeRate(const std::string &rate) const
{
	std::istringstream iss(rate);
    double value;
    if (!(iss >> value))
        return false;
    return iss.eof();
}

void BitcoinExchange::exchange(/*std::ifstream &file*/)
{
	_addExchangeRateAndDatesToMap();

	for (std::map<std::string, double>::iterator it = _exchangeRate.begin(); it != _exchangeRate.end(); ++it)
	{
		std::cout << "Date: " << it->first << ", value: " << it->second << std::endl;
	}
	
}

const char *BitcoinExchange::NoFileError::what() const throw()
{
	return "ERROR: Could not open file. Please provide a valid file.\n";
}

const char *BitcoinExchange::MissingDataError::what() const throw()
{
	return "ERROR: The file you provided is missing the required data. Please provide a valid file.\n";
}

const char *BitcoinExchange::InvalidDataFormatError::what() const throw()
{
	return "ERROR: The data within the file does not have the required format. Please provide a valid file.\n";
}

const char *BitcoinExchange::OutOfRangeError::what() const throw()
{
	return "ERROR: The data within the file exceeds the required ranges. Please provide a valid file.\n";
}
