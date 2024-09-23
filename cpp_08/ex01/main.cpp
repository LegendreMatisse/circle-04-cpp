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
		std::cerr << e.what() << std::flush;
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
		std::cerr << e.what() << std::flush;
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
		std::cerr << e.what() << std::flush;
	}

	std::cout << "--__--__--__--__--" << std::endl;

	Span *spanTest4 = new Span(5);

	try
	{
		spanTest4->addNumberBulk(6, 3, 17, 9, 11);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::flush;
	}

	try
	{
		std::cout << spanTest3->shortestSpan() << std::endl;
		std::cout << spanTest3->longestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::flush;
	}

	return (0);
}