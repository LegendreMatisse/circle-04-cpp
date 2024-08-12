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

int main(void)
{
	std::cout << "Creating the various animals..." << std::endl;
	const Animal* meta	= new Animal();
	const Animal* j		= new Dog();
	const Animal* i		= new Cat();

	std::cout << "\nPrinting the types of the various animals..." << std::endl;
	std::cout << "meta: " << meta->getType() << std::endl;
	std::cout << "j: " << j->getType() << std::endl;
	std::cout << "i: " << i->getType() << std::endl;

	std::cout << "\nCalling the makeSound function for the various animals..." << std::endl;
	meta->makeSound();
	j->makeSound();
	i->makeSound();

	std::cout << "\nDeleting the various animals..." << std::endl;
	delete(meta);
	delete(j);
	delete(i);

	std::cout << "\nThe wrong animals are here..." << std::endl;
	std::cout << "\nMay the Gods have mercy on our souls..." << std::endl;
	const WrongAnimal* steve	= new WrongAnimal;

	std::cout << "\nPrinting the types of the various wrong animals..." << std::endl;
	std::cout << "meta: " << steve->getType() << std::endl;
	std::cout << "j: " << karl->getType() << std::endl;

	std::cout << "\nCalling the makeSound function for the various wrong animals..." << std::endl;
	steve->makeSound();
	karl->makeSound();

	std::cout << "\nDeleting the various wrong animals..." << std::endl;
	delete(steve);
	delete(karl);
	
	return (0);
}