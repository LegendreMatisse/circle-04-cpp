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

std::vector<int> Span::prepVector() const
{
	if (this->_spanVec.size() == 0)
		throw EmptySpanEx();
	if (this->_spanVec.size() < 2)
		throw NotEnoughNumbersEx();

	std::vector<int> temp(this->_spanVec);

	std::sort(temp.begin(), temp.end());

	std::vector<int> span(temp.size());

	std::adjacent_difference(temp.begin(), temp.end(), span.begin());

	return span;
}

int Span::shortestSpan() const
{
	int lowestSpan = std::numeric_limits<int>::max();
	std::vector<int> temp(this->prepVector());

	for (std::vector<int>::iterator it = temp.begin(); it != temp.end(); ++it) 
	{
		if (*it < lowestSpan && *it > 0)
			lowestSpan = *it;
	}

	return lowestSpan;
}

int Span::longestSpan() const
{
	int highestSpan = std::numeric_limits<int>::min();
	std::vector<int> temp(this->prepVector());

	for (std::vector<int>::iterator it = temp.begin(); it != temp.end(); ++it) 
	{
		if (*it > highestSpan)
			highestSpan = *it;
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