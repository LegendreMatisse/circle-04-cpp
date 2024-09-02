/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:26:50 by mlegendr          #+#    #+#             */
/*   Updated: 2024/09/02 15:26:50 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	std::cout << "An instance of ScalarConverter was created." << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "An instance of ScalarConverter was destroyed." << std::endl;
}

void ScalarConverter::convert(const std::string &in)
{
	//conversion 1
	try
	{
		int val = std::atoi(in.c_str());
		std::cout << "char: " << std::flush;
		if (std::isprint(val))
			std::cout << "'" << static_cast<char>(val) << "'" << std::endl;
		else
			throw std::exception();
	}
	catch(const std::exception& e)
	{
		std::cout << "cannot be printed." << std::endl; 
	}
	
	//conversion 2
	try
	{
		int val = std::atoi(in.c_str());
		std::cout << "int: " << std::flush;
		if (in == "nan" || in == "nanf" || in == "+inf" || in == "+inff" || in == "-inf" || in == "-inff")
			throw std::exception();
		if (val >= std::numeric_limits<int>::min() && val <= std::numeric_limits<int>::max())
			std::cout << "'" << static_cast<int>(val) << "'" << std::endl;
		else
			throw std::exception();
	}
	catch(const std::exception& e)
	{
		std::cout << "cannot be printed." << std::endl; 
	}

	//conversion 3
	try
	{
		float val = std::atof(in.c_str());
		std::cout << "float: " << std::flush;
		if (std::isinf(val) || std::isnan(val) || (val >= -std::numeric_limits<float>::max() && val <= std::numeric_limits<float>::max()) || val == 0.0f)
			std::cout << "'" << std::fixed << std::setprecision(1) << static_cast<float>(val) << "f'" << std::endl;
		else
			throw std::exception();
	}
	catch(const std::exception& e)
	{
		std::cout << "cannot be printed." << std::endl; 
	}

	//conversion 4
	try
	{
		double val = std::strtod(in.c_str(), NULL);
		std::cout << "double: " << std::flush;
		if (std::isinf(val) || std::isnan(val) || (val >= -std::numeric_limits<double>::max() && val <= std::numeric_limits<double>::max()) || val == 0.0)
			std::cout << "'" << std::fixed << std::setprecision(1) << static_cast<double>(val) << "'" << std::endl;
		else
			throw std::exception();
	}
	catch(const std::exception& e)
	{
		std::cout << "cannot be printed." << std::endl; 
	}
}