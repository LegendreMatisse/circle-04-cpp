/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:06:45 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/12 17:06:45 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main(void)
{
	/*This will give a compile error, intentional design xoxo*/
	// Animal test;

	Cat *catArray[5];
	Dog *dogArray[5];

	for (size_t i = 0; i < 5; i++)
	{
		std::cout << "Creating cat[" << i << "]: " << std::endl;
		catArray[i] = new Cat();
		std::cout << catArray[i]->getType() << std::endl;
		catArray[i]->makeSound();
		std::cout << "--__--__--__--__--" << std::endl;
	}

	for (size_t i = 0; i < 5; i++)
	{
		std::cout << "Creating dog[" << i << "]: " << std::endl;
		dogArray[i] = new Dog();
		std::cout << dogArray[i]->getType() << std::endl;
		dogArray[i]->makeSound();
		std::cout << "--__--__--__--__--" << std::endl;
	}

	for (size_t i = 0; i < 5; i++)
	{
		std::cout << "Deleting cat[" << i << "]: " << std::endl;
		delete catArray[i];
		std::cout << "--__--__--__--__--" << std::endl;
	}
	
	for (size_t i = 0; i < 5; i++)
	{
		std::cout << "Deleting dog[" << i << "]: " << std::endl;
		delete dogArray[i];
		std::cout << "--__--__--__--__--" << std::endl;
	}
	
	return (0);
}