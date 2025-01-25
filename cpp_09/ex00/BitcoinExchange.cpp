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

void BitcoinExchange::_validateDate(const std::string &date) const
{
	if (date.size() != 10)
		throw InvalidDataFormatError();
	for (int i = 0; i < date.size(); i++)
	{
		if (!std::isdigit(date[i]) && date[i] != '-')
			throw InvalidDataFormatError();
		else
			continue;
	}
	
	int year = _convertStringToInt(date.substr(0, 4));
	int month = _convertStringToInt(date.substr(5, 2));
	int day = _convertStringToInt(date.substr(8, 2));

	if (!_checkIfRealDate(year, month, day))
		throw InvalidDataFormatError();
}

int BitcoinExchange::_convertStringToInt(const std::string &input) const
{
	std::istringstream iss(input);
	int output = 0;

	iss >> output;

	if (iss.fail() || !iss.eof())

		throw InvalidDataFormatError();

	return output;
}

void BitcoinExchange::_checkIfRealDate(const int year, const int month, const int day) const
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

void BitcoinExchange::exchange(std::ifstream &file)
{
	(void)file;

	std::cout << "1" << std::endl;
	_validateDate("2012-12-12");
	std::cout << "2" << std::endl;
	_validateDate("2012-12-aa");
	std::cout << "3" << std::endl;
	_validateDate("2012/12/12");
	std::cout << "4" << std::endl;
	_validateDate("2012-12-2");
	std::cout << "5" << std::endl;
	_validateDate("2012-02-17");
	std::cout << "6" << std::endl;
	_validateDate("2024-02-29");
	std::cout << "7" << std::endl;
	_validateDate("2024-02-28");

}