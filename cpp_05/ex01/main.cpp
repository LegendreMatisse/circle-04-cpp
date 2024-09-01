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
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
