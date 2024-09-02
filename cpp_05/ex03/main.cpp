/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 21:55:17 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/17 21:55:17 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main(void)
{
	try
	{
		std::cout << "Test 1" << std::endl;
		Intern *steve = new Intern();

		steve->chooseForm("robotomy request", "Bender");

		delete steve;

		std::cout << "--__--__--__--__--" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "Test 2" << std::endl;
		Intern *bart = new Intern();

		bart->chooseForm("shrubbery creation", "The knights who say ni");

		delete bart;

		std::cout << "--__--__--__--__--" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "Test 2" << std::endl;
		Intern *karl = new Intern();

		karl->chooseForm("presidential pardon", "Rick Shanchez");

		delete karl;

		std::cout << "--__--__--__--__--" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "Test 3" << std::endl;
		Intern *ken = new Intern();

		ken->chooseForm("fail", "fail");

		delete ken;

		std::cout << "--__--__--__--__--" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
