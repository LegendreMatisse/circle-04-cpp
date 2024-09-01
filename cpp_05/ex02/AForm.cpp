/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:20:09 by mlegendr          #+#    #+#             */
/*   Updated: 2024/09/01 19:20:09 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _signed(false), _name("default"), _signGrade(150), _execGrade(150)
{
	std::cout << "An instance of a form was created." << std::endl;
}

//parameterised constructor
AForm::AForm(const std::string &name, const unsigned int &signGrade, const unsigned int &execGrade) : _signed(false), _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	if (this->_signGrade < 1 || this->_execGrade < 1)
		throw AForm::GradeTooHighException();
	else if (this->_signGrade > 150 || this->_execGrade > 150)
		throw AForm::GradeTooLowException();
	else if (this->_signGrade > this->_execGrade)
		throw AForm::GradeTooHighException();
	std::cout << "An instance of a form was created." << std::endl;
}

//copy constructor
AForm::AForm(const AForm &copyCo) : _signed(copyCo._signed), _name(copyCo._name), _signGrade(copyCo._signGrade), _execGrade(copyCo._execGrade)
{
	std::cout << "An instance of a form was created by copy." << std::endl;
}

//assignement operator overload
AForm &AForm::operator=(const AForm &copyOp)
{
	if (this == &copyOp)
		return *this;
	this->_signed = copyOp._signed;
	std::cout << "An instance of a form has been assigned." << std::endl;
	return *this;
}

//destructor
AForm::~AForm()
{
	std::cout << "An instance of a form was destroyed." << std::endl;
}

//getters
bool AForm::getSigned(void) const
{
	return this->_signed;
}

std::string AForm::getName(void) const
{
	return this->_name;
}

unsigned int AForm::getSignGrade(void) const
{
	return this->_signGrade;
}

unsigned int AForm::getExecGrade(void) const
{
	return this->_execGrade;
}

//functions
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->getSigned() == true)
	{
		throw AForm::FormSignedException();
	}
	else if (bureaucrat.getGrade() > this->getSignGrade())
	{
		throw AForm::GradeTooLowException();
	}
	this->_signed = true;
	std::cout << "The form has been signed by the bureaucrat." << std::endl;
}

void execute(const Bureaucrat &executor) const
{
	if (this->getSigned() == true)
		throw AForm::FormSignedException();
	else if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	this->specialFeature();
}

//exception classes
const char *AForm::GradeTooLowException::what() const throw()
{
	return ("The grade of the bureaucrat is too low to sign or execute the form.\n");
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("The grade of the bureaucrat falls outside of the allowed range.\n");
}

const char *AForm::FormSignedException::what() const throw()
{
	return ("The form is already signed.\n");
}

//overloads
std::ostream &operator<<(std::ostream &out, AForm const &value)
{
	out << "The form: " << value.getName() << " has a sign grade of: " << value.getSignGrade();
	out << ", it can be executed by a grade of " << value.getExecGrade() << " or higher." << std::endl;
	if (value.getSigned() == true)
		out << "It has been signed." << std::endl;
	else
		out << "It has not been signed." << std::endl;
	return out;
}