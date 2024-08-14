/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:51:37 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/14 16:51:37 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "A brain has been created" << std::endl;
}

Brain::Brain(const Brain &copyCo)
{
	std::cout << "A brain has been created by copy" << std::endl;
	*this = copyCo;
}

Brain &Brain::operator=(const Brain &copyOp)
{
	if (this == &copyOp)
		return *this;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = copyOp._ideas[i];
	std::cout << "A brain has been assigned" << std::endl;
	return *this;
}

Brain::~Brain()
{
	std::cout << "A brain has been destroyed" << std::endl;
}

const std::string	&Brain::getIdea(const int i) const
{
	static const std::string emptyString = "";
	//if (i < 0 || i >= sizeof(_ideas) / sizeof(_ideas[0]))
	if (i < 0 || i >= 100)
	{
		std::cout << "The index is out of bounds" << std::endl;
		return emptyString;
		
	}
	return this->_ideas[i];
}

void Brain::setIdea(const std::string &idea, int i)
{
	this->_ideas[i] = idea;
}