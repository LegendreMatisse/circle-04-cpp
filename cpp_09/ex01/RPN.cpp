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
	calculateResult(_inputWithoutSpaces);
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

	int operandCount = 0;
	int operatorCount = 0;

	for (size_t i = 0; i < (size_t)_inputWithoutSpaces.size(); i++)
	{
		if (std::isdigit(_inputWithoutSpaces[i]))
			operandCount++;
		else
			operatorCount++;

		if (!(operandCount > operatorCount))
			throw WrongInputError();
	}
	
	char lastValue = _inputWithoutSpaces[_inputWithoutSpaces.size() - 1];

	if (lastValue != '+' && lastValue != '-' && lastValue != '/' && lastValue != '*')
		throw WrongInputError();

	return;
}

void RPN::calculateResult(const std::string &input)
{
	(void)input;
	for (size_t i = 0; i < (size_t)_inputWithoutSpaces.size(); i++)
	{
		if (std::isdigit(_inputWithoutSpaces[i]))
			_expression.push(_inputWithoutSpaces[i] - '0');
		else if (_inputWithoutSpaces[i] == '+' || _inputWithoutSpaces[i] == '-' || _inputWithoutSpaces[i] == '/' || _inputWithoutSpaces[i] == '*')
		{
			if (_expression.size() < 2)
				throw WrongInputError();
			int b = _expression.top();
			_expression.pop();
			int a = _expression.top();
			_expression.pop();
			int result = _performOperation(a, b, _inputWithoutSpaces[i]);
			_expression.push(result);
		}
		else
			throw WrongInputError();
	}
	
	/*std::istringstream iss(input);
	std::string expressionPart;

	while (iss >> expressionPart)
	{
		if (std::isdigit(expressionPart[0]))
		{
			_expression.push(expressionPart[0] - '0');
			std::cout << "4" << std::endl;
		}
		else if (expressionPart == "+" || expressionPart == "-" || expressionPart == "/" || expressionPart == "*")
		{
			std::cout << "9" << std::endl;
			if (_expression.size() < 2)
				throw WrongInputError();
			int b = _expression.top();
			_expression.pop();
			int a = _expression.top();
			_expression.pop();
			int result = _performOperation(a, b, expressionPart);
			_expression.push(result);
			std::cout << "5" << std::endl;
		}
		else
		{
			std::cout << "11" << std::endl;
			throw WrongInputError();
		}
	}*/

	if (_expression.size() != 1)
		throw WrongInputError();
	
	std::cout << _expression.top() << std::endl;
}

int RPN::_performOperation(const int &a, const int &b, const char &expressionPart)
{
	if (expressionPart == '+')
		return a + b;
	if (expressionPart == '-')
		return a - b;
	if (expressionPart == '*')
		return a * b;
	if (expressionPart == '/')
	{
		if (b == 0)
			throw WrongInputError();
		return a / b;
	}
	throw WrongInputError();
}

const char *RPN::WrongInputError::what() const throw()
{
	std::cout << "ERROR: The provided input is wrong. Try again." << std::endl;
	return "";
}