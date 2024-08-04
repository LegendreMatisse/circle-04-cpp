/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:59:31 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/04 16:59:31 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	public:
		//constructor
		HumanB(std::string name);

		//destructor
		~HumanB();

		//getter
		std::string getName() const;

		//setter
		void setWeapon(Weapon &weapon);

		//function
		void attack() const;

	private:
		std::string _name;
		Weapon *_weapon;
};

#endif