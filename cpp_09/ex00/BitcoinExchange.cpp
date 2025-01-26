/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 00:38:01 by mlegendr          #+#    #+#             */
/*   Updated: 2025/01/26 00:38:01 by mlegendr         ###   ########.fr       */
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

void BitcoinExchange::_validateDate(const std::string &date)
{
	if (date.size() != 10)
		throw InvalidDataFormatError();
	for (size_t i = 0; i < date.size(); i++)
	{
		if (!std::isdigit(date[i]) && date[i] != '-')
			throw InvalidDataFormatError();
		else
			continue;
	}
	
	int year = _convertStringToInt(date.substr(0, 4));
	int month = _convertStringToInt(date.substr(5, 2));
	int day = _convertStringToInt(date.substr(8, 2));

	_checkIfRealDate(year, month, day);
}

int BitcoinExchange::_convertStringToInt(const std::string &input)
{
	std::istringstream iss(input);
	int output = 0;

	iss >> output;

	if (iss.fail() || !iss.eof())
		throw InvalidDataFormatError();

	return output;
}

void BitcoinExchange::_checkIfRealDate(const int year, const int month, const int day)
{
	if (month < 1 || month > 12) 
		throw InvalidDataFormatError();
    if (day < 1 || day > 31)
		throw InvalidDataFormatError();
    if (month == 2)
	{
        bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if (isLeapYear && day != 29)
			throw InvalidDataFormatError();
		else if (!isLeapYear && day != 28)
			throw InvalidDataFormatError();
    }
    if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day != 30)
			throw InvalidDataFormatError();
	}
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

		_validateDate(date);
		_validateExchangeRate(rate);

		if (date.empty() || rate.empty())
			throw InvalidDataFormatError();
		if (_exchangeRate.find(date) != _exchangeRate.end())
			throw MissingDataError();

		std::string concateDate = date.substr(0, 4) + date.substr(5, 2) + date.substr(8, 2);

		_exchangeRate[concateDate] = std::strtod(rate.c_str(), NULL);
	}
}

void BitcoinExchange::_validateExchangeRate(const std::string &rate)
{
	std::istringstream iss(rate);
	double value = 0;

	iss >> value;

	if (iss.fail() || !iss.eof())
		throw InvalidDataFormatError();
}

void BitcoinExchange::exchange(std::ifstream &file)
{
	(void)file;

	_addExchangeRateAndDatesToMap();
}

const char *BitcoinExchange::NoFileError::what() const throw()
{
	std::cout << "ERROR: Could not open file. Please provide a valid file." << std::endl;
	return "";
}

const char *BitcoinExchange::MissingDataError::what() const throw()
{
	std::cout << "ERROR: The file you provided is missing the required data. Please provide a valid file." << std::endl;
	return "";
}

const char *BitcoinExchange::InvalidDataFormatError::what() const throw()
{
	std::cout << "ERROR: The data within the file does not have the required format. Please provide a valid file." << std::endl;
	return "";
}

const char *BitcoinExchange::OutOfRangeError::what() const throw()
{
	std::cout << "ERROR: The data within the file exceeds the required ranges. Please provide a valid file." << std::endl;
	return "";
}