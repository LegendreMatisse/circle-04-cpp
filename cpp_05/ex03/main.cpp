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

		steven->chooseForm("robotomy request", "Bender");

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
		Intern *steve = new Intern();

		steven->chooseForm("shrubbery creation", "The knights who say ni");

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
		Intern *steve = new Intern();

		steven->chooseForm("presidential pardon", "Rick Shanchez");

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
		Intern *steve = new Intern();

		steven->chooseForm("fail", "fail");

		delete steven;

		std::cout << "--__--__--__--__--" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
