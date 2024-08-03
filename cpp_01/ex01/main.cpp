/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 23:16:59 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/03 23:16:59 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main(void)
{
	Zombie *horde;

	horde = zombieHorde(5, "Steven");

	for (int i = 0; i < 5; i++)
	{
		horde[i].announce();
	}

	delete[] horde;
	
	return (0);
}