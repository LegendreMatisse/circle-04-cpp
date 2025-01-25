/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:35:46 by mlegendr          #+#    #+#             */
/*   Updated: 2025/01/19 15:35:46 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <ctype.h>

class RPN
{
	private:
		//variables
		std::stack<char> _expression;
		std::string _inputWithoutSpaces;

		//fucntions
		void _inputValidation(const std::string &input);
		int _performOperation(const int &a, const int &b, const char &expressionPart);

		//constructors
		RPN();
	
	public:
		//constructors and destructor
		RPN(const std::string &input);
		RPN(const RPN &copyCo);
		RPN &operator=(const RPN &copyOp);
		~RPN();

		//functions
		void calculateResult(const std::string &input);

		//exceptions
		class WrongInputError : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif