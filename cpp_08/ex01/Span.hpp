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

		std::vector<int> prepVector() const;
		void addNumber(const int num);
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
};

#endif