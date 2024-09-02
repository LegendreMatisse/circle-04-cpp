/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:04:53 by mlegendr          #+#    #+#             */
/*   Updated: 2024/09/02 16:04:53 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base *generate(void)
{
	std::srand(std::time(0));
	int i = std::rand() % 3;
	if (i == 0)
		return (new A);
	if (i == 1)
		return (new B);
	else
		return (new C);
}

void identify(Base *pointer)
{
	if (dynamic_cast<A*>(pointer))
		std::cout << "The class is of type: A." << std::endl;
	else if (dynamic_cast<B*>(pointer))
		std::cout << "The class is of type: B." << std::endl;
	else if (dynamic_cast<C*>(pointer))
		std::cout << "The class is of type: C." << std::endl;
}

void identify(Base &reference)
{
	if (dynamic_cast<A*>(&reference))
		std::cout << "The class is of type: A." << std::endl;
	else if (dynamic_cast<B*>(&reference))
		std::cout << "The class is of type: B." << std::endl;
	else if (dynamic_cast<C*>(&reference))
		std::cout << "The class is of type: C." << std::endl;
}