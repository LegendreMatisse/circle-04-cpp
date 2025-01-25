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
		static bool _comparePairs(const std::pair<int, int> &a, const std::pair<int, int> &b);

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
		std::pair<int, int> _makeOrderedPair(const T &unsortedContainerIT, const T &sortedContainerIT)
		{
			return (unsortedContainerIT < sortedContainerIT) ? std::make_pair(unsortedContainerIT, sortedContainerIT) : std::make_pair(sortedContainerIT, unsortedContainerIT);
		}

		template <typename T>
		void _fillAndSortPairsList(T &unsortedContainer, T &sortedContainer, std::list<std::pair<int, int> > &pairs)
		{
			typename T::iterator unsortedContainerIT = unsortedContainer.begin();
			typename T::iterator sortedContainerIT = sortedContainer.begin();

			while (unsortedContainerIT != unsortedContainer.end() && sortedContainerIT != sortedContainer.end())
			{
				pairs.push_back(_makeOrderedPair(*unsortedContainerIT, *sortedContainerIT));
				++unsortedContainerIT;
				++sortedContainerIT;
			}

			pairs.sort(_comparePairs);
		}

		template <typename T>
		void _handleOddElement(T &container, int tmp)
		{
			if (tmp != std::numeric_limits<int>::min()) {
				container.push_back(tmp);
			}
		}

		template <typename T>
		int _extractOddElement(T &container)
		{
			if (container.size() % 2 != 0)
			{
				int tmp = container.back();
				container.pop_back();
				return tmp;
			}
			return std::numeric_limits<int>::min();
		}

		template <typename T>
		T _extractHalfOfContainer(T &container)
		{
			int i = 0;
			int j = container.size() / 2;
			T tmp;
			
			while (i < j)
			{
				tmp.push_back(container.front());
				container.pop_front();
				i++;
			}
			return tmp;
		}

		template <typename T>
		void _fillContainerWithPairs(T &unsortedContainer, T &sortedContainer,  std::list<std::pair<int, int> > &pairs)
		{
			unsortedContainer.clear();
			sortedContainer.clear();

			std::list<std::pair<int, int> >::iterator itPair = pairs.begin();
			
			while (itPair != pairs.end())
			{
				unsortedContainer.push_back(itPair->first);
				unsortedContainer.push_back(itPair->second);
				++itPair;
			}
		}

		template <typename T>
		void _sortAndPushToSorted(T &unsortedContainer, T &sortedContainer)
		{
			while (!unsortedContainer.empty()) 
			{
				std::list<int>::iterator min_it = std::min_element(unsortedContainer.begin(), unsortedContainer.end());
				sortedContainer.push_back(*min_it);
				unsortedContainer.erase(min_it);
			}
		}

		template <typename T>
		void _sortContainer(T &unsortedContainer, T &sortedContainer)
		{
			int tmp = _extractOddElement(unsortedContainer);

			sortedContainer = _extractHalfOfContainer(unsortedContainer);

			std::list<std::pair<int, int> > pairs;

			_fillAndSortPairsList(unsortedContainer, sortedContainer, pairs);

			_fillContainerWithPairs(unsortedContainer, sortedContainer, pairs);

			_handleOddElement(unsortedContainer, tmp);

			_sortAndPushToSorted(unsortedContainer, sortedContainer);
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