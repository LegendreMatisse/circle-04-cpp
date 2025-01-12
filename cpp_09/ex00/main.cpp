/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:33:12 by mlegendr          #+#    #+#             */
/*   Updated: 2024/09/25 18:33:12 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc!= 2)
	{
		std::cout << "ERROR: Wrong number of arguments. Please provide a valid file.\n" << std::endl;
		return 1;
	}

	std::ifstream input(argv[1]);
	if (!input.is_open())
	{
		std::cout << "ERROR: Could not open file. Please provide a valid file.\n" << std::endl;
		return 1;
	}

	BitcoinExchange bitcoin;

	try
	{
		bitcoin.exchange(input);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::flush;
	}

	return 0;
}