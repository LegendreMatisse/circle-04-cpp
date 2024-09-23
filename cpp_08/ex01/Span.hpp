/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 00:03:04 by mlegendr          #+#    #+#             */
/*   Updated: 2024/09/23 00:03:04 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <exception>
#include <limits>
#include <cstdarg>
#include <cctype>

class Span
{
	private:
		unsigned int _count;
		std::vector<int> _spanVec;

	public:
		//constructor
		Span();

		//parameterised const
		Span(unsigned int count);

		//copy constructor
		Span(const Span &copyCo);

		//assignment operator overload
		Span &operator=(const Span &copyOp);

		//destructor
		~Span();

		void addNumber(const int num);
		void addNumberBulk(const unsigned int count, ...);
		int shortestSpan() const;
		int longestSpan() const;

		class SpanFullEx : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class EmptySpanEx : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class NotEnoughNumbersEx : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class NotANumberEx : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif