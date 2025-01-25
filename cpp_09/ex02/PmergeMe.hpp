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