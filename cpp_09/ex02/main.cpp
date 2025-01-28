/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:33:56 by mlegendr          #+#    #+#             */
/*   Updated: 2025/01/28 17:17:33 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <typeinfo>
#include <vector>
#include <list>
#include <string>

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc <= 2)
	{
		std::cout << "ERROR: Wrong number of arguments. Please provide a valid input." << std::endl;
		return 1;
	}

	PmergeMe pmm;

	try
	{
		for (int i = 1; i < argc; i++)
		{
			pmm.fillInputList(argv[i]);
		}
		
		pmm.sort();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	
	return 0;
}