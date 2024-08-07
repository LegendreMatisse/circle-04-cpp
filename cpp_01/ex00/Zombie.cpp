/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:13:15 by mlegendr          #+#    #+#             */
/*   Updated: 2024/07/31 20:40:32 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "Zombie raised from the dead..." << std::endl;
}

Zombie::Zombie(std::string &name) : _name(name)
{
	std::cout << Zombie::getName() << " raised from the dead..." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << Zombie::getName() << " was banished from this realm..." << std::endl;
}

std::string	Zombie::getName(void) const
{
	return this->_name;
}

void	Zombie::announce(void)
{
	std::cout << Zombie::getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}