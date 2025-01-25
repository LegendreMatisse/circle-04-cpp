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
			if (!_checkContainerType(container))
				throw WrongInputError();

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
		int _checkContainerType(T &container)
		{
			const std::string containerNames[2] = {"vector", "list"};
			const std::string containerName = typeid(container).name();

			for (size_t i = 0; i < 2; i++)
			{
				if (containerName.find(i) != std::string::npos)
					return 0;
			}
			return 1;
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