/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 21:55:17 by mlegendr          #+#    #+#             */
/*   Updated: 2024/09/19 15:33:28 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	try
	{
		std::cout << "Test 1" << std::endl;
		unsigned int tempGrade = 150;
		Bureaucrat *steven = new Bureaucrat("Steven", tempGrade);
		ShrubberyCreationForm *bush = new ShrubberyCreationForm("Steven");

		std::cout << *steven;
		std::cout << *bush;

		steven->executeForm(*bush);

		delete steven;
		delete bush;

		std::cout << "--__--__--__--__--" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "Test 1" << std::endl;
		unsigned int tempGrade = 1;
		Bureaucrat *steven = new Bureaucrat("Steven", tempGrade);
		PresidentialPardonForm *bush = new PresidentialPardonForm("Steven");

		std::cout << *steven;
		std::cout << *bush;

		steven->executeForm(*bush);

		delete steven;
		delete bush;

		std::cout << "--__--__--__--__--" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "Test 1" << std::endl;
		unsigned int tempGrade = 1;
		Bureaucrat *steven = new Bureaucrat("Steven", tempGrade);
		RobotomyRequestForm *bush = new RobotomyRequestForm("Steven");

		std::cout << *steven;
		std::cout << *bush;

		steven->executeForm(*bush);

		delete steven;
		delete bush;

		std::cout << "--__--__--__--__--" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
