/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 21:54:49 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/17 21:54:49 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		std::cout << "Test 1" << std::endl;
		unsigned int tempGrade = 19;
		Bureaucrat *steven = new Bureaucrat("Steven", tempGrade);
		try
		{
			steven->incrementGrade();
			steven->decrementGrade();
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << *steven;
		delete steven;
		std::cout << "--__--__--__--__--" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "Test 2" << std::endl;
		unsigned int tempGrade = 1;
		Bureaucrat *steven = new Bureaucrat("Steven", tempGrade);
		try
		{
			steven->incrementGrade();
			steven->decrementGrade();
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << *steven;
		delete steven;
		std::cout << "--__--__--__--__--" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "Test 3" << std::endl;
		unsigned int tempGrade = 150;
		Bureaucrat *steven = new Bureaucrat("Steven", tempGrade);
		try
		{
			steven->incrementGrade();
			steven->decrementGrade();
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << *steven;
		delete steven;
		std::cout << "--__--__--__--__--" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "Test 4" << std::endl;
		unsigned int tempGrade = 200;
		Bureaucrat *steven = new Bureaucrat("Steven", tempGrade);
		try
		{
			steven->incrementGrade();
			steven->decrementGrade();
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << *steven;
		delete steven;
		std::cout << "--__--__--__--__--" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}