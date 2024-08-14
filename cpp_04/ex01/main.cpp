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
	Animal *animalArray[10];

	for (size_t i = 0; i < 5; i++)
	{
		animalArray[i] = new Cat();
		std::cout << animalArray[i]->getType() << std::endl;
		animalArray[i]->makeSound();
		std::cout << "--__--__--__--__--" << std::endl;
	}

	for (size_t i = 5; i < 10; i++)
	{
		animalArray[i] = new Dog();
		std::cout << animalArray[i]->getType() << std::endl;
		animalArray[i]->makeSound();
		std::cout << "--__--__--__--__--" << std::endl;
	}

	/*Dog dogTest = animalArray[6];
	std::cout << dogTest.getType() << std::endl;
	dogTest.makeSound();
	std::cout << "--__--__--__--__--" << std::endl;

	Cat catTest = animalArray[2];
	std::cout << catTest.getType() << std::endl;
	catTest.makeSound();
	std::cout << "--__--__--__--__--" << std::endl;

	Cat deepCatTest = catTest;
	std::cout << deepCatTest.getType() << std::endl;
	deepCatTest.makeSound();
	std::cout << "--__--__--__--__--" << std::endl;*/

	Cat *copyTest = new Cat(animalArray[2]);
	std::cout << copyTest.getType() << std::endl;
	copyTest.makeSound();
	std::cout << "--__--__--__--__--" << std::endl;

	for (size_t i = 0; i < 10; i++)
	{
		delete animalArray[i];
	}
	
	delete copyTest;

	return (0);
}