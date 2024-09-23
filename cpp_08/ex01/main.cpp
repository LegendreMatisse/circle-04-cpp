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
	try
	{
		Span *spanTest1 = new Span(5);

		spanTest1->addNumber(6);
		spanTest1->addNumber(3);
		spanTest1->addNumber(17);
		spanTest1->addNumber(9);
		spanTest1->addNumber(11);

		std::cout << spanTest1->shortestSpan() << std::endl;
		std::cout << spanTest1->longestSpan() << std::endl;

		delete spanTest1;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::flush;
	}

	std::cout << "--__--__--__--__--" << std::endl;

	try
	{
		Span *spanTest2 = new Span(0);

		std::cout << spanTest2->shortestSpan() << std::endl;
		std::cout << spanTest2->longestSpan() << std::endl;

		delete spanTest2;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::flush;
	}

	std::cout << "--__--__--__--__--" << std::endl;

	try
	{
		Span *spanTest3 = new Span(1);

		spanTest3->addNumber(6);

		std::cout << spanTest3->shortestSpan() << std::endl;
		std::cout << spanTest3->longestSpan() << std::endl;

		delete spanTest3;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::flush;
	}

	std::cout << "--__--__--__--__--" << std::endl;

	try
	{
		std::string command = "";

		std::cout << "Enter a size: " << std::flush;
        std::getline(std::cin, command);

		std::stringstream ss(command);
		int num = 0;
		ss >> num;

		Span *spanTest4 = new Span(num);

		spanTest4->addNumberBulk();

		std::cout << spanTest4->shortestSpan() << std::endl;
		std::cout << spanTest4->longestSpan() << std::endl;

		delete spanTest4;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::flush;
	}

	std::cout << "--__--__--__--__--" << std::endl;

	try
	{
		std::string command = "";

		std::cout << "Enter a size: " << std::flush;
        std::getline(std::cin, command);

		std::stringstream ss(command);
		int num = 0;
		ss >> num;

		Span *spanTest5 = new Span(num);

		spanTest5->addNumberBulk();

		std::cout << spanTest5->shortestSpan() << std::endl;
		std::cout << spanTest5->longestSpan() << std::endl;

		delete spanTest5;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::flush;
	}

	return (0);
}