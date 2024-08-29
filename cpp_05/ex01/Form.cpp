/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:19:08 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/29 20:45:31 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("default"), _signGrade(150), _execGrade(150), _signed(false)
{
	std::cout << "An instance of a form was created." << std::endl;
}

//parameterised constructor
Form::Form(const std::string &name, const unsigned int &signGrade, const unsigned int &execGrade) : _name(name)
{
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
	this->_signGrade = signGrade;
	this->_execGrade = execGrade;
	this->_signed = false;
	std::cout << "An instance of a form was created." << std::endl;
}

//copy constructor

//assignement operator overload

//destructor

//getters

//functions

//exception classes

//overloads