/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:35:49 by mlegendr          #+#    #+#             */
/*   Updated: 2025/01/19 15:35:49 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
	std::cout << "Default constructor called" << std::endl;
}

RPN::RPN(const std::string &input)
{
	std::cout << "Constructor with parameters called" << std::endl;
	_inputValidation(input);
	//_calculateResult();
}

RPN::RPN(const RPN &copyCo)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copyCo;
}

RPN &RPN::operator=(const RPN &copyOp)
{
	if (this == &copyOp)
		return *this;
	_expression = copyOp._expression;
	std::cout << "Assignement constructor called" << std::endl;
	return *this;
}

RPN::~RPN()
{
	std::cout << "Destructor called" << std::endl;
}

void RPN::_inputValidation(const std::string &input)
{
	for (size_t i = 0; i < (size_t)input.size(); i++)
	{
		if (input[i] == ' ')
			continue;

		if (!std::isdigit(input[i]) && input[i] != '+' && input[i] != '-' && input[i] != '/' && input[i] != '*')
			throw WrongInputError();

		_inputWithoutSpaces += input[i];
	}

	for (size_t i = 0; i < (size_t)_inputWithoutSpaces.size(); i++)
	{
		int operandCount = 0;
		int operatorCount = 0;

		if (std::isdigit(_inputWithoutSpaces[i]))
			operandCount++;
		else
			operatorCount++;

		if (operandCount == operatorCount || operandCount < operatorCount)
			throw WrongInputError();
	}
	
	char lastValue = _inputWithoutSpaces[_inputWithoutSpaces.size()];

	std::cout << lastValue << std::endl;

	if (lastValue != '+' && lastValue != '-' && lastValue != '/' && lastValue != '*')
		throw WrongInputError();

	std::cout << _inputWithoutSpaces << std::endl;

	return;
}

/*void RPN::calculateResult(const std::string &input)
{
	std::istringstream iss(input);
	std::string = expressionPart;

	while (iss >> expressionPart)
	{
		if (_expressionPart.size() == 1 && std::isdigit(expressionPart[0]))
			_expression.push(expressionPart);
		else if (input != '+' && input != '-' && input != '/' && input != '*')
		
	}
}*/

const char *RPN::WrongInputError::what() const throw()
{
	std::cout << "ERROR: The provided input is wrong. Try again." << std::endl;
	return "";
}