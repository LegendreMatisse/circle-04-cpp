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
		Bureaucrat *steven = new Bureaucrat("Steven", 19);
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
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat *steven = new Bureaucrat("Steven", 1);
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
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat *steven = new Bureaucrat("Steven", 100);
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
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}