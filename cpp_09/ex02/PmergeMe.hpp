/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:02:39 by mlegendr          #+#    #+#             */
/*   Updated: 2025/01/25 17:02:39 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <sstream>
#include <limits>
#include <typeinfo>

class PmergeMe
{
	private:
		//variables
		std::list<int> _inputList;
		std::list<int> _unsortedList;
		std::list<int> _sortedList;
		std::vector<int> _unsortedVector;
		std::vector<int> _sortedVector;

		//functions
		int _validateInput(const std::string &argvInput);

		//templates
		template <typename T>
		void _printContainerContent(const T &container, bool before)
		{
			if (before)
				std::cout << "Before: " << std::flush;
			else
				std::cout << "After: " << std::flush;

			typename T::const_iterator it;
				for (it = container.begin(); it != container.end(); ++it)
					std::cout << *it << " ";
				std::cout << std::endl;
		}

		template <typename T>
		void _fillContainerWithInputList(T &container)
		{
			for (std::list<int>::iterator it = _inputList.begin(); it != _inputList.end(); ++it)
			{
				container.push_back(*it);
			}
		}

		template <typename T>
		std::string _returnContainerType(T &container)
		{
			std::vector<std::string> containerTypes;
			containerTypes.push_back("vector");
			containerTypes.push_back("list");

			const std::string fullContainerId = typeid(container).name();

			for (std::vector<std::string>::iterator it = containerTypes.begin(); it != containerTypes.end(); ++it)
			{
				if (fullContainerId.find(*it) != std::string::npos)
					return *it;
			}
			throw WrongInputError();
		}

		template <typename T>
		void _printSortTime(T &container, double elapsedTime)
		{
			std::cout << "Time to process range of " << container.size() << " elements with std::" << std::flush;
			std::cout << _returnContainerType(container) << std::flush;
			std::cout << " : " << elapsedTime << "us" << std::endl;
		}

		template <typename T>
		void _sortContainer(T &unsortedContainer, T &sortedContainer)
		{
			size_t size = unsortedContainer.size();
			int tmp = std::numeric_limits<int>::min();

			if (size % 2 != 0)
			{
				tmp = unsortedContainer.back();
				unsortedContainer.pop_back();
			}

			for (size_t i = 0; i < size / 2; i++)
			{
				sortedContainer.push_back(unsortedContainer.front());
				unsortedContainer.pop_front();
			}

			std::list<std::pair<int, int> > pairs;
			std::list<int>::iterator unsortedContainerIt = unsortedContainer.begin();
			std::list<int>::iterator sortedContainerIt = sortedContainer.begin();

			while (unsortedContainerIt != unsortedContainer.end() && sortedContainerIt != sortedContainer.end())
			{
				if (*unsortedContainerIt < * sortedContainerIt)
					pairs.push_back(std::make_pair(*unsortedContainerIt, *sortedContainerIt));
				else
					pairs.push_back(std::make_pair(*sortedContainerIt, *unsortedContainerIt));
				unsortedContainerIt++;
				sortedContainerIt++;
			}

			pairs.sort(std::bind(&PmergeMe::_comparePairs, this, std::placeholders::_1, std::placeholders::_2));

			unsortedContainer.clear();
			sortedContainer.clear();

			for (std::list<std::pair<int, int> >::iterator itPair = pairs.begin(); itPair != pairs.end(); ++itPair)
			{
				unsortedContainer.push_back(itPair->first);
				unsortedContainer.push_back(itPair->second);
			}

			if (tmp != -1)
				unsortedContainer.push_back(tmp);

			while (!unsortedContainer.empty()) 
			{
				std::list<int>::iterator min_it = std::min_element(unsortedContainer.begin(), unsortedContainer.end());
				sortedContainer.push_back(*min_it);
				unsortedContainer.erase(min_it);
			}		
			}

	public:
		//constructors and destructor
		PmergeMe();
		PmergeMe(const PmergeMe &copyCo);
		PmergeMe &operator=(const PmergeMe &copyOp);
		~PmergeMe();

		//functions
		void fillInputList(const std::string &argvInput);
		void sort();

		//exceptions
		class WrongInputError : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};


#endif