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

Form::Form(void) : _signed(false), _name("default"), _signGrade(150), _execGrade(150)
{
	std::cout << "An instance of a form was created." << std::endl;
}

//parameterised constructor
Form::Form(const std::string &name, const unsigned int &signGrade, const unsigned int &execGrade) : _signed(false), _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	if (this->_signGrade < 1 || this->_execGrade < 1)
		throw Form::GradeTooHighException();
	else if (this->_signGrade > 150 || this->_execGrade > 150)
		throw Form::GradeTooLowException();
	else if (this->_signGrade > this->_execGrade)
		throw Form::GradeTooHighException();
	std::cout << "An instance of a form was created." << std::endl;
}

//copy constructor
Form::Form(const Form &copyCo) : _signed(copyCo._signed), _name(copyCo._name), _signGrade(copyCo._signGrade), _execGrade(copyCo._execGrade)
{
	std::cout << "An instance of a form was created by copy." << std::endl;
}

//assignement operator overload
Form &Form::operator=(const Form &copyOp)
{
	if (this == &copyOp)
		return *this;
	this->_signed = copyOp._signed;
	std::cout << "An instance of a form has been assigned." << std::endl;
	return *this;
}

//destructor
Form::~Form()
{
	std::cout << "An instance of a form was destroyed." << std::endl;
}

//getters
bool Form::getSigned(void)
{
	return this->_signed;
}

std::string Form::getName(void)
{
	return this->_name;
}

unsigned int Form::getSignGrade(void)
{
	return this->_signGrade;
}

unsigned int Form::getExecGrade(void)
{
	return this->_execGrade;
}

//functions
void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->getSigned() == true)
	{
		std::cout << "This form is already signed." << std::endl;
		return ;
	}
	else if (bureaucrat.getGrade() > this->getSignGrade())
	{
		std::cout << "The grade of the bureaucrat is too low to sign the form." << std::endl;
		throw Form::GradeTooLowException();
	}
	this->_signed = true;
	std::cout << "The form has been signed by the bureaucrat." << std::endl;
}

//exception classes
const char *Form::GradeTooLowException::what() const throw()
{
	return ("The grade of the bureaucrat is too low to sign or execute the form.\n");
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("The grade of the bureaucrat falls outside of the allowed range.\n");
}

//overloads
std::ostream &operator<<(std::ostream &out, Form const &value)
{
	out << "The form: " << value.getName() << " has a sign grade of: " << value->getSignGrade();
	out << ", it can be executed by a grade of " << value.getExecGrade() << " or higher." << std::endl;
	if (value.getSigned == true)
		out << "It has been signed." << std::endl;
	else
		out << "It has not been signed." << std::endl;
	return out;
}