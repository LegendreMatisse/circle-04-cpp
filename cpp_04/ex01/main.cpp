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
		std::cout << "Creating cat[" << i << "]: " << std::endl;
		animalArray[i] = new Cat();
		std::cout << animalArray[i]->getType() << std::endl;
		animalArray[i]->makeSound();
		std::cout << "Brain address: " << dynamic_cast<Cat*>(animalArray[i])->getBrainAddress() << std::endl; 
		std::cout << "--__--__--__--__--" << std::endl;
	}

	for (size_t i = 5; i < 10; i++)
	{
		std::cout << "Creating dog[" << i << "]: " << std::endl;
		animalArray[i] = new Dog();
		std::cout << animalArray[i]->getType() << std::endl;
		animalArray[i]->makeSound();
		std::cout << "Brain address: " << dynamic_cast<Dog*>(animalArray[i])->getBrainAddress() << std::endl;
		std::cout << "--__--__--__--__--" << std::endl;
	}

	std::cout << "Creating copy of dog (animalArray[6]): " << std::endl;
	Dog dogTest = *dynamic_cast<Dog*>(animalArray[6]);
	std::cout << dogTest.getType() << std::endl;
	dogTest.makeSound();
	std::cout << "Brain address: " << dogTest.getBrainAddress() << std::endl;
	std::cout << "--__--__--__--__--" << std::endl;

	std::cout << "Creating copy of cat (animalArray[2]): " << std::endl;
	Cat catTest = *dynamic_cast<Cat*>(animalArray[2]);
	std::cout << catTest.getType() << std::endl;
	catTest.makeSound();
	std::cout << "Brain address: " << catTest.getBrainAddress() << std::endl;
	std::cout << "--__--__--__--__--" << std::endl;

	std::cout << "Creating copy of copy of cat: " << std::endl;
	Cat deepCatTest = catTest;
	std::cout << deepCatTest.getType() << std::endl;
	deepCatTest.makeSound();
	std::cout << "Brain address: " << deepCatTest.getBrainAddress() << std::endl;
	std::cout << "--__--__--__--__--" << std::endl;

	std::cout << "Creating copy of copy of copy of cat (animalArray[2]): " << std::endl;
	Cat *copyTest = new Cat(*dynamic_cast<Cat*>(animalArray[2]));
	std::cout << copyTest->getType() << std::endl;
	copyTest->makeSound();
	std::cout << "Brain address: " << copyTest->getBrainAddress() << std::endl;
	std::cout << "--__--__--__--__--" << std::endl;

	for (size_t i = 0; i < 10; i++)
	{
		std::cout << "Deleting animal[" << i << "]: " << std::endl;
		delete animalArray[i];
		std::cout << "--__--__--__--__--" << std::endl;
	}
	
	delete copyTest;

	return (0);
}