/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:58:38 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/04 16:58:38 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("cannon loaded with grapeshot");
		HumanA bob("Jim Bob The Third", club);
		bob.attack();
		club.setType("deadly bio-engineered virus");
		bob.attack();
	}
	{
		Weapon club = Weapon("briefcase nuke");
		HumanB jim("Jim Carlsson the Viscount of Montperllier");
		jim.setWeapon(club);
		jim.attack();
		club.setType("weaponized incompetence");
		jim.attack();
	}
	return (0);
}SSS