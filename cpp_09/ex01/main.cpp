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
		RPN test(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	/*try
	{
		RPN test("1 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 +");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}

	try
	{
		RPN test("1 q + 3 + 4 + 5 + 6 + 7 + 8 + 9 +");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}

	try
	{
		RPN test("1+3+4+5+6+7+8+9+");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	
	try
	{
		RPN test("12+3+4+5+6+7+8+9");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}*/

	return 0;
}