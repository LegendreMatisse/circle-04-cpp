/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:22:18 by mlegendr          #+#    #+#             */
/*   Updated: 2024/09/18 12:28:54 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
	std::cout << "--- Container is a vector of int's ---" << std::endl;
	std::vector<int> test;

	test.push_back(10);
    test.push_back(20);
    test.push_back(30);

	try
	{
		std::vector<int>::const_iterator it = easyfind(test, 20);
		std::cout << *it << std::endl;	
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		std::vector<int>::const_iterator it = easyfind(test, 9500);
		std::cout << *it << std::endl;	
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
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
	

	std::list<int> test2;

	test2.push_back(10);
    test2.push_back(20);
    test2.push_back(30);
	
	try
	{
		std::list<int>::const_iterator it = easyfind(test2, 20);
		std::cout << *it << std::endl;	
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		std::list<int>::const_iterator it = easyfind(test2, 9500);
		std::cout << *it << std::endl;	
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	try
	{
		std::list<int> test2;
		std::list<int>::const_iterator it = easyfind(test2, 20);
		std::cout << *it << std::endl;	
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return (0);
}