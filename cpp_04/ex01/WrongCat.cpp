/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 00:49:45 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/13 00:49:45 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	std::cout << "A WrongCat has been constructed." << std::endl;
	this->setType("WrongCat");
}

WrongCat::WrongCat(WrongCat const &copyCo) : WrongAnimal(copyCo)
{
	std::cout << "A WrongCat has been created by copy." << std::endl;
	*this = copyCo;
}

WrongCat &WrongCat::operator=(WrongCat const &copyOp)
{
	if (this == &copyOp)
		return *this;
	_type = copyOp._type;
	std::cout << "A WrongCat has been assigned" << std::endl;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "A WrongCat has been destroyed." << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout << "**unintelligible eldritch screaming**" << std::endl;
}