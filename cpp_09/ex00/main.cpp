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
	if (argc != 2)
	{
		std::cout << "ERROR: Wrong number of arguments. Please provide a valid file.\n" << std::flush;
		return 1;
	}

	BitcoinExchange bitcoin;
	std::ifstream inputFile;

	try
	{
		bitcoin.openInputFile(argv[1], inputFile);
		bitcoin.exchange(inputFile);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}

	return 0;
}