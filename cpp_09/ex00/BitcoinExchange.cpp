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

		std::string concateDate = date.substr(0, 4) + date.substr(5, 7) + date.substr(8, 10);
		_exchangeRateSorted[concateDate] = std::strtod(rate.c_str(), NULL);

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

	int year = _convertStringToInt(date.substr(0, 4));
	int month = _convertStringToInt(date.substr(5, 7));
	int day = _convertStringToInt(date.substr(8, 10));

	if (!_checkIfRealDate(year, month, day))
		return false;

	return true;
}

int BitcoinExchange::_convertStringToInt(const std::string &input) const
{
	std::istringstream iss(input);
	int output = 0;

	iss >> output;

	if (iss.fail())
		throw InvalidDataFormatError();

	return output;
}

bool BitcoinExchange::_checkIfRealDate(const int year, const int month, const int day) const
{
	if (month < 1 || month > 12) 
		return false;
    if (day < 1 || day > 31)
		return false;
    if (month == 2)
	{
        bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        return day <= (isLeapYear ? 29 : 28);
    }
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return day <= 30;
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

void BitcoinExchange::exchange(std::ifstream &file)
{
	std::string input;
	std::getline(file, input);
	if (input != "date | value")
		throw InvalidDataFormatError();

	_addExchangeRateAndDatesToMap();
	
	while (std::getline(file, input))
	{
		try
		{
			std::string date = input.substr(0, input.find('|') - 1);
			std::string value = input.substr(input.find('|') + 2);

			if (date.empty() || value.empty())
				throw InvalidDataFormatError();
			if (!_validateDate(date))
				throw InvalidDataFormatError();
			if (std::strtod(value.c_str(), NULL) <= 0 || std::strtod(value.c_str(), NULL) > 1000)
				throw OutOfRangeError();
			
			/*if (_exchangeRate.find(date) == _exchangeRate.end())
				std::cout << "Date not found." << std::endl;

			std::cout << "Found value: " << _exchangeRate[date] << std::endl;*/

			std::cout << date.substr(0, 4) + date.substr(5, 7) + date.substr(8, 10) << std::endl;
			std::cout << date.substr(0, 4) << std::endl;
			std::cout << date.substr(5, 7) << std::endl;
			std::cout << date.substr(8, 10) << std::endl;

			std::cout << date << " => " << value << " = " << std::fixed << std::setprecision(2) << std::strtod(value.c_str(), NULL) * _exchangeRate[date] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what();
		}
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
