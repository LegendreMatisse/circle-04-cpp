/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:33:39 by mlegendr          #+#    #+#             */
/*   Updated: 2024/09/25 18:33:39 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "ERROR: The provided input is wrong. Try again." << std::endl;
		return 1;
	}

	try
	{
		std::cout << "~~" << std::endl;
		RPN test(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}

	std::cout << "Tests from the subject." << std::endl;

	try
	{
		std::cout << "~~" << std::endl;
		std::cout << "Result should be: 42" << std::endl;
		RPN test("8 9 * 9 - 9 - 9 - 4 - 1 +");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}

	try
	{
		std::cout << "~~" << std::endl;
		std::cout << "Result should be: 42" << std::endl;
		RPN test("7 7 * 7 -");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}

	try
	{
		std::cout << "~~" << std::endl;
		std::cout << "Result should be: 0" << std::endl;
		RPN test("1 2 * 2 / 2 * 2 4 - +");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}

	try
	{
		std::cout << "~~" << std::endl;
		std::cout << "Result should be: Error" << std::endl;
		RPN test("(1 + 1)");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}

	try
	{
		std::cout << "~~" << std::endl;
		std::cout << "Result should be: Error" << std::endl;
		RPN test("");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}

	return 0;
}