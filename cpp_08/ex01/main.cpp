/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 00:03:11 by mlegendr          #+#    #+#             */
/*   Updated: 2024/09/23 00:03:11 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
	std::vector<int> test;

	test.push_back(6);
	test.push_back(3);
	test.push_back(17);
	test.push_back(9);
	test.push_back(11);

	int lowestSpan = 0;
	int highestSpan = 0;
	int temp = 0;
	
	std::sort(test.begin(), test.end());

	for (std::vector<int>::iterator it = test.begin(); it != test.end(); ++it)
	{
		for (std::vector<int>::iterator er = test.begin(); er != test.end(); ++er)
		{
			if (*it > *er && *it != *er)
				temp = *it - *er;
			else if (*it < *er && *it != *er)
				temp = *er - *it;
			if (lowestSpan == 0 && highestSpan == 0)
				lowestSpan = temp;
			if (temp < lowestSpan)
				lowestSpan = temp;
			if (temp > highestSpan)
				highestSpan = temp;
		}
	}
	
	std::cout << lowestSpan << std::endl;
	std::cout << highestSpan << std::endl;

	lowestSpan = 0;
	highestSpan = 0;

	std::sort(test.begin(), test.end());

	std::vector<int> differences(test.size());

	std::adjacent_difference(test.begin(), test.end(), differences.begin());

	for (size_t i = 1; i < differences.size(); ++i) {
		if (differences[i] < lowestSpan && differences[i] > 0) {
			lowestSpan = differences[i];
		}
		if (differences[i] > highestSpan) {
			highestSpan = differences[i];
		}
	}

	std::cout << lowestSpan << std::endl;
	std::cout << highestSpan << std::endl;

	std::cout << "--__--__--__--__--" << std::endl;

	Span *spanTest1 = new Span(5);

	spanTest1->addNumber(6);
	spanTest1->addNumber(3);
	spanTest1->addNumber(17);
	spanTest1->addNumber(9);
	spanTest1->addNumber(11);

	try
	{
		std::cout << spanTest1->shortestSpan() << std::endl;
		std::cout << spanTest1->longestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "--__--__--__--__--" << std::endl;

	Span *spanTest2 = new Span(0);

	try
	{
		std::cout << spanTest2->shortestSpan() << std::endl;
		std::cout << spanTest2->longestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "--__--__--__--__--" << std::endl;

	Span *spanTest3 = new Span(1);

	spanTest3->addNumber(6);

	try
	{
		std::cout << spanTest3->shortestSpan() << std::endl;
		std::cout << spanTest3->longestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}