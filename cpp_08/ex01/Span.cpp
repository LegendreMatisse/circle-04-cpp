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
	if (this == &copyCo)
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

std::vector<int> Span::prepVector()
{
	if (this->_spanVec.size() == 0)
		throw EmptySpanEx();
	if (this->_spanVec.size() < 2)
		throw NotEnoughNumbersEx();

	std::vector<int> temp(this->_spanVec);
	std::sort(temp.begin(), temp.end());

	std::vector<int> span(temp.size());

	std::adjacent_difference(temp.begin(), temp.end(), span.begin());

	return temp;
}

int Span::shortestSpan() const
{
	int lowestSpan = 0;
	std::vector<int> temp = prepVector();

	for (size_t i = 1; i < differences.size(); ++i) 
	{
		if (differences[i] < lowestSpan && differences[i] > 0)
			lowestSpan = differences[i];
	}

	return lowestSpan;
}

int Span::longestSpan() const
{
	int highestSpan = 0;
	std::vector<int> temp = prepVector();

	for (size_t i = 1; i < differences.size(); ++i) 
	{
		if (differences[i] > highestSpan)
			highestSpan = differences[i];
	}

	return highestSpan;
}

const char *Span::SpanFullEx::what() const throw()
{
	return ("The span is already at full capacity.\n");
}

const char *Span::NoSpanEx::what() const throw()
{
	return ("The span is empty.\n");
}

const char *Span::NotEnoughNumbersEx::what() const throw()
{
	return ("There is only 1 number is the span.\n");
}