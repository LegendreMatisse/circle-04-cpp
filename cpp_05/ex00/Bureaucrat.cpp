/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 21:56:44 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/17 21:56:44 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150)
{
	std::cout << "An instance of a bureaucrat was created." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, unsigned int &grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
	std::cout << "An instance of a bureaucrat was created." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copyCo)
{
	*this = copyCo;
	std::cout << "An instance of a bureaucrat was created by copy." << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &copyOp)
{
	if (this == &copyOp)
		return *this;
	this->_name = copyOp._name;
	this->_grade = copyOp._grade;
	std::cout << "An instance of a bureaucrat has been assigned." << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "An instance of a bureaucrat was destroyed." << std::endl;
}

std::string Bureaucrat::getName(void) const
{
	return this->_name;
}

unsigned int Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

void Bureaucrat::incrementGrade(void)
{
	if (--this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade(void)
{
	if (++this->_grade < 1)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The grade of the bureaucrat " + getName() + " is too low.\n");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The grade of the bureaucrat is too high.\n");
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &value)
{
	out << value.getName() << ", bureaucrat grade " << value.getGrade() << "." << std::endl;
	return out;
}
