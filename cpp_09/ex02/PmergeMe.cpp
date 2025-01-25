/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:02:33 by mlegendr          #+#    #+#             */
/*   Updated: 2025/01/25 17:02:33 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	std::cout << "Default constructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &copyCo)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copyCo;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copyOp)
{
	if (this == &copyOp)
		return *this;
	_inputList = copyOp._inputList;
	_unsortedList = copyOp._unsortedList;
	_sortedList = copyOp._sortedList;
	_unsortedVector = copyOp._unsortedVector;
	_sortedVector = copyOp._sortedVector;
	std::cout << "Assignement constructor called" << std::endl;
	return *this;
}

PmergeMe::~PmergeMe()
{
	std::cout << "Destructor called" << std::endl;
}

void PmergeMe::fillInputList(const std::string &argvInput)
{
	int input = _validateInput(argvInput);

	_inputList.push_back(input);
}

int PmergeMe::_validateInput(const std::string &argvInput)
{
	std::istringstream iss(argvInput);

	int input = 0;

	iss >> input;

	if (iss.fail() || !iss.eof())
		throw WrongInputError();
	
	if (input < 0 || input > std::numeric_limits<int>::max())
		throw WrongInputError();

	return input;
}

static bool PmergeMe::_findBiggestPair(const std::pair<int, int> &unsorted, const std::pair<int, int> &sorted)
{
	return unsorted.first < sorted.first;
}

void PmergeMe::sort()
{
	_fillContainerWithInputList(_unsortedList);
	_fillContainerWithInputList(_unsortedVector);
	_printContainerContent(_unsortedList, true);
	_sortContainer(_unsortedList, _sortedList);
	_printContainerContent(_unsortedList, false);
}

const char *PmergeMe::WrongInputError::what() const throw()
{
	std::cout << "ERROR: The provided input is wrong. Try again." << std::endl;
	return "";
}