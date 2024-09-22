/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 00:03:07 by mlegendr          #+#    #+#             */
/*   Updated: 2024/09/23 00:03:07 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
	std::cout << "default constructor called" << std::endl;
}

Span::Span(unsigned int count) : _count(count)
{
	std::cout << "parameterised constructor called" << std::endl;
}

Span::Span(const Span &copyCo)
{
	*this = copyCo;
	std::cout << "copy constructor called" << std::endl;
}

Span &Span::operator=(const Span &copyOp)
{
	if (this == &copyOp)
		return *this;
	this->_count = copyOp._count;
	this->_spanVec = copyOp._spanVec;
	std::cout << "copy assignment operator called" << std::endl;
	return *this;
}

Span::~Span()
{
	std::cout << "destructor called" << std::endl;
}

void Span::addNumber(const int num)
{
	if (this->_spanVec.size() == this->_count)
		throw Span::SpanFullEx();
	this->_spanVec.push_back(num);
}

int Span::shortestSpan() const
{
	if (this->_spanVec.size() == 0)
		throw EmptySpanEx();
	if (this->_spanVec.size() < 2)
		throw NotEnoughNumbersEx();

	int lowestSpan = std::numeric_limits<int>::max();
	std::vector<int> temp(this->_spanVec);

	std::sort(temp.begin(), temp.end());

	std::vector<int> span(temp.size());

	std::adjacent_difference(temp.begin(), temp.end(), span.begin());

	for (std::vector<int>::const_iterator it = span.begin(); it != span.end(); ++it) 
	{
		if (*it < lowestSpan && *it > 0)
			lowestSpan = *it;
	}

	return lowestSpan;
}

int Span::longestSpan() const
{
	if (this->_spanVec.size() == 0)
		throw EmptySpanEx();
	if (this->_spanVec.size() < 2)
		throw NotEnoughNumbersEx();

	int highestSpan = std::numeric_limits<int>::min();
	int temp = 0;

	for (std::vector<int>::const_iterator it = _spanVec.begin(); it != _spanVec.end(); ++it)
	{
		for (std::vector<int>::const_iterator er = _spanVec.begin(); er != _spanVec.end(); ++er)
		{
			if (*it > *er && *it != *er)
				temp = *it - *er;
			else if (*it < *er && *it != *er)
				temp = *er - *it;
			if (highestSpan == std::numeric_limits<int>::min())
				highestSpan = temp;
			if (temp > highestSpan)
				highestSpan = temp;
		}
	}

	return highestSpan;
}

const char *Span::SpanFullEx::what() const throw()
{
	return ("The span is already at full capacity.\n");
}

const char *Span::EmptySpanEx::what() const throw()
{
	return ("The span is empty.\n");
}

const char *Span::NotEnoughNumbersEx::what() const throw()
{
	return ("There is only 1 number is the span.\n");
}