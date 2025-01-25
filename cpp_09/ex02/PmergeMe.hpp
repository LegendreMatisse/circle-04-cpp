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
		std::pair<int, int> _makeOrderedPair(const T &unsorted, const T &sorted)
		{
			return (unsorted < sorted) ? std::make_pair(unsorted, sorted) : std::make_pair(sorted, unsorted);
		}

		template <typename T>
		void _handleOddElement(T &container, int tmp)
		{
			if (tmp != std::numeric_limits<int>::min()) {
				container.push_back(tmp);
			}
		}

		template <typename T>
		int _handleOddSize(T &container)
		{
			if (container.size() % 2 != 0)
			{
				int last = container.back();
				container.pop_back();
				return last;
			}
			return std::numeric_limits<int>::min();
		}

		template <typename T>
		T _extractHalf(T &container)
		{
			T firstHalf;
			for (size_t i = 0; i < container.size() / 2; i++) {
				firstHalf.push_back(container.front());
				container.pop_front();
			}
			return firstHalf;
		}

		template <typename T>
		std::list<std::pair<int, int> > _createPairs(T &firstHalf, T &secondHalf)
		{
			std::list<std::pair<int, int> > pairs;
			typename T::iterator itFirst = firstHalf.begin();
			typename T::iterator itSecond = secondHalf.begin();

			while (itFirst != firstHalf.end() && itSecond != secondHalf.end()) {
				if (*itFirst < *itSecond)
					pairs.push_back(std::make_pair(*itFirst, *itSecond));
				else
					pairs.push_back(std::make_pair(*itSecond, *itFirst));

				++itFirst;
				++itSecond;
			}
			return pairs;
		}

		template <typename T>
		void _mergePairsIntoContainer(const std::list<std::pair<int, int> > &pairs, T &container)
		{
			for (typename std::list<std::pair<int, int> >::const_iterator itPair = pairs.begin(); itPair != pairs.end(); ++itPair) {
				container.push_back(itPair->first);
				container.push_back(itPair->second);
			}
		}

		template <typename T>
		void _finalizeSort(T &container)
		{
			T tempContainer;
			while (!container.empty()) {
				typename T::iterator minIt = std::min_element(container.begin(), container.end());
				tempContainer.push_back(*minIt);
				container.erase(minIt);
			}
			container.swap(tempContainer);
		}

		template <typename T>
		void _sortContainer(T &unsortedContainer, T &sortedContainer)
		{
			int tmp = _handleOddSize(unsortedContainer);

			T firstHalf = _extractHalf(unsortedContainer);
			T secondHalf = unsortedContainer;

			std::list<std::pair<int, int> > pairs = _createPairs(firstHalf, secondHalf);

			pairs.sort(_comparePairs);

			unsortedContainer.clear();
			sortedContainer.clear();

			_mergePairsIntoContainer(pairs, sortedContainer);

			_handleOddElement(unsortedContainer, tmp);

			_finalizeSort(sortedContainer);		
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