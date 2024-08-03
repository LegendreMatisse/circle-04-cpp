/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 23:17:53 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/03 23:17:53 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int n, std::string name)
{
	Zombie horde[n];

	for (int i = 0; i < n; i++)
	{
		horde[i] = Zombie(name);
	}
	return horde;
	/*Zombie	*horde = new Zombie[n];
	for (int i = 0; i < n; i++)
	{
		horde[i].setName(name);
	}
	return horde;*/
}