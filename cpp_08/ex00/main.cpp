/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:22:18 by mlegendr          #+#    #+#             */
/*   Updated: 2024/09/16 18:13:46 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
	std::vector<int> test;

	test.push_back(10);
    test.push_back(20);
    test.push_back(30);

	try
	{
		std::vector<int> test2;
		std::vector<int>::const_iterator it = easyfind(test2, 20);
		std::cout << *it << std::endl;	
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	return (0);
}