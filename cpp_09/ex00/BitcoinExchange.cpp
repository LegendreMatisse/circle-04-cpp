/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 09:59:38 by mlegendr          #+#    #+#             */
/*   Updated: 2025/01/26 09:59:38 by mlegendr         ###   ########.fr       */
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

std::ifstream &BitcoinExchange::openInputFile(const std::string &filename, std::ifstream &file)
{
	file.open(filename.c_str());
	if (!file.is_open())
		throw NoFileError();
	return (file);
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

std::string BitcoinExchange::_convertIntToString(const int &input)
{
	std::stringstream ss;

	ss << input;

	return ss.str();
}

void BitcoinExchange::_fillExchangeRateMapWithDateAndRate(std::ifstream &file)
{
	std::string line;
	std::string date;
	std::string concatenatedDate;
	std::string rate;

	while (std::getline(file, line))
	{
		if (line == "date,exchange_rate")
			continue;

		date = line.substr(0, line.find(','));
		concatenatedDate = _checkDate(date);

		rate = line.substr(line.find(',') + 1);
		_checkRate(rate);

		_exchangeRate[date] = std::strtof(rate.c_str(), NULL);
	}
	file.close();
}

std::string BitcoinExchange::_checkDate(const std::string &date)
{
	if (date.empty())
		throw InvalidDataFormatError();
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

	std::string temp = _convertIntToString(year) + _convertIntToString(month) + _convertIntToString(day);

	std::cout << "temp concat: " << temp << std::cout;

	return _convertIntToString(year) + _convertIntToString(month) + _convertIntToString(day);
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
		if (isLeapYear && day > 29)
			throw InvalidDataFormatError();
		else if (!isLeapYear && day > 28)
			throw InvalidDataFormatError();
	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
			throw InvalidDataFormatError();
	}
}

void BitcoinExchange::_checkRate(const std::string &rate)
{
	if (rate.empty())
		throw InvalidDataFormatError();
	std::istringstream iss(rate);
	float value = 0;

	iss >> value;

	if (iss.fail() || !iss.eof())
		throw InvalidDataFormatError();
}

void BitcoinExchange::exchange(std::ifstream &file)
{
	std::ifstream dataFile;
	openInputFile("data.csv", dataFile);
	_fillExchangeRateMapWithDateAndRate(dataFile);

	std::string line;
	std::string date;
	std::string concatenatedDate;
	std::string bitcoinCount;
	float bitcoinCountFloat;

	while (std::getline(file, line))
	{
		try
		{
			if (line == "date | value")
				continue;

			date = line.substr(0, line.find('|') - 1);
			concatenatedDate = _checkDate(date);

			std::cout << "date: " << date << std::endl;

			bitcoinCount = line.substr(line.find('|') + 2);

			std::cout << "bitcoinCount: " << bitcoinCount << std::endl;

			_checkRate(bitcoinCount);
			bitcoinCountFloat = std::strtof(bitcoinCount.c_str(), NULL);

			std::cout << "bitcoinCountFloat: " << bitcoinCountFloat << std::endl;

			if (bitcoinCountFloat <= 0.0f || bitcoinCountFloat > 1000.0f)
				throw OutOfRangeError();

			std::map<std::string, float>::iterator it = _exchangeRate.lower_bound(concatenatedDate);

			std::cout << "it->first: " << it->first << " it->second: " << it->second << std::endl;

			if (it == _exchangeRate.end() || it->first != concatenatedDate)
			{
				if (it == _exchangeRate.begin())
					throw InvalidDataFormatError();
				--it;
			}

			std::cout << date << " => " << bitcoinCount << " = "
					  << std::fixed << std::setprecision(2)
					  << bitcoinCountFloat * it->second << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what();
		}
	}
	file.close();
}

const char *BitcoinExchange::NoFileError::what() const throw()
{
	std::cout << "ERROR: Could not open file. Please provide a valid file." << std::endl;
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