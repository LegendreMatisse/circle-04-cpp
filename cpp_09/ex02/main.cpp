/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:33:56 by mlegendr          #+#    #+#             */
/*   Updated: 2024/09/25 18:33:56 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <typeinfo>
#include <vector>
#include <list>
#include <string>

int main(void)
{
	std::vector<int> v;
	std::list<int> l;
	int a[18];

	std::vector<std::string> containerNames;

	containerNames.push_back("vector");
	containerNames.push_back("list");
	containerNames.push_back("deque");

	std::string containerName = typeid(v).name();

	for (std::vector<std::string>::iterator it = containerNames.begin(); it != containerNames.end(); ++it)
	{
		if (containerName.find(*it) != std::string::npos)
			std::cout << "The container type is: " << *it << std::endl;
		else
			std::cout << "This container type is not supported by this program." << std::endl;
	}
	
	containerName = typeid(l).name();

	for (std::vector<std::string>::iterator it = containerNames.begin(); it != containerNames.end(); ++it)
	{
		if (containerName.find(*it) != std::string::npos)
			std::cout << "The container type is: " << *it << std::endl;
		else
			std::cout << "This container type is not supported by this program." << std::endl;
	}

	containerName = typeid(a).name();

	for (std::vector<std::string>::iterator it = containerNames.begin(); it != containerNames.end(); ++it)
	{
		if (containerName.find(*it) != std::string::npos)
			std::cout << "The container type is: " << *it << std::endl;
		else
			std::cout << "This container type is not supported by this program." << std::endl;
	}

	return 0;

}