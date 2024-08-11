/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 17:29:19 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/11 17:29:19 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	protected:
		std::string	#name;
		int			#hitPoints;
		int			#energyPoints;
		int			#attackDamage;

	public:
		//constructor
		ClapTrap(void);

		//parameterized constructor
		ClapTrap(std::string name);

		//copy constructor
		ClapTrap(const ClapTrap &copyCo);

		//assignment operator overload
		ClapTrap &operator=(const ClapTrap &copyOp);

		//destructor
		~ClapTrap();

		//getters
		std::string	getName(void) const;
		int			getHitPoints(void) const;
		int			getEnergyPoints(void) const;
		int			getAttackDamage(void) const;

		//setters
		void		setName(std::string name);
		void		setHitPoints(int hitpoints);
		void		setEnergyPoints(int energyPoints);
		void		setAttackDamage(int attackDamage);

		//functions
		void		attack(std::string const &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		determineMessage(std::string const &message, std::string const &target, int amount);

		//debug functions
		void		printStats(void);
};

#endif