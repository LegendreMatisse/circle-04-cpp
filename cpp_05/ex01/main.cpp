/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 21:55:01 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/17 21:55:01 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		std::cout << "Test 1" << std::endl;
		unsigned int tempGrade = 19;
		Bureaucrat *steven = new Bureaucrat("Steven", tempGrade);
		Form *form1 = new Form("Banana", tempGrade, tempGrade);

		std::cout << *steven;
		std::cout << *form1;

		steven->signForm(*form1);

		std::cout << *form1;

		delete steven;
		delete form1;

		std::cout << "--__--__--__--__--" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "Test 2" << std::endl;
		unsigned int burGrade = 19;
		unsigned int signGrade = 1;
		unsigned int execGrade = 19;
		Bureaucrat *steven = new Bureaucrat("Steven", burGrade);
		Form *form1 = new Form("Banana", signGrade, execGrade);

		std::cout << *steven;
		std::cout << *form1;

		steven->signForm(*form1);

		std::cout << *form1;

		delete steven;
		delete form1;

		std::cout << "--__--__--__--__--" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "Test 3" << std::endl;
		unsigned int burGrade = 19;
		unsigned int signGrade = 200;
		unsigned int execGrade = 19;
		Bureaucrat *steven = new Bureaucrat("Steven", burGrade);
		Form *form1 = new Form("Banana", signGrade, execGrade);

		std::cout << *steven;
		std::cout << *form1;

		steven->signForm(*form1);

		std::cout << *form1;

		delete steven;
		delete form1;

		std::cout << "--__--__--__--__--" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
