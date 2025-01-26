/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 14:19:27 by mlegendr          #+#    #+#             */
/*   Updated: 2024/12/25 14:19:27 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <exception>
#include <cstdlib>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

class BitcoinExchange {

	private:
		//variables
		std::map<std::string, float> _exchangeRate;

		//functions
		void _fillExchangeRateMapWithDateAndRate(std::ifstream &file);
		std::string _checkDate(const std::string &date);
		void _checkIfRealDate(const int year, const int month, const int day);
		int _convertStringToInt(const std::string &input);
		std::string _convertIntToString(const int &input);
		void _checkRate(const std::string &rate);

	public:
		//constructors and destructor
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copyCo);
		BitcoinExchange &operator=(const BitcoinExchange &copyOp);
		~BitcoinExchange();

		//functions
		std::ifstream &openInputFile(const std::string &filename, std::ifstream &file);
		void exchange(std::ifstream &file);

		//exceptions
		class NoFileError : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class InvalidDataFormatError : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class OutOfRangeError : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};

#endif //BITCOINEXCHANGE_HPP
