/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:35:25 by mlegendr          #+#    #+#             */
/*   Updated: 2024/07/31 20:39:17 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main(void)
{
	Zombie zombie;
	Zombie zombie2(&name2);
	std::string name = "Steven";
	std::string name2 = "Bob";

	zombie.setName(name);

	zombie.announce();
	zombie2.announce();

	return (0);
}