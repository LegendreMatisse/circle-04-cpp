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

class BitcoinExchange {

	private:
		//variables
		std::map<std::string, double> _exchangeRate;
		std::map<std::string, double> _exchangeRateSorted;

		//functions
		void _addExchangeRateAndDatesToMap();
		bool _validateDate(const std::string &date) const;
		int _convertStringToInt(const std::string &input) const;
		bool _checkIfRealDate(const int year, const int month, const int day) const;
		bool _validateExchangeRate(const std::string &rate) const;



	public:
		//constructors and destructor
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copyCo);
		BitcoinExchange &operator=(const BitcoinExchange &copyOp);
		~BitcoinExchange();

		//functions
		void exchange(std::ifstream &file);

		//exceptions
		class NoFileError : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class MissingDataError : public std::exception
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
