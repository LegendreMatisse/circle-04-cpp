/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 17:29:55 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/11 17:29:55 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		//constructor
		ScavTrap(void);

		//parameterized constructor
		ScavTrap(std::string const &name);

		//copy constructor
		ScavTrap(const ScavTrap &copyCo);

		//assignment operator overload
		ScavTrap &operator=(const ScavTrap &copyOp);

		//destructor
		~ScavTrap();

		//functions
		void	attack(std::string const &target);
		void	guardGate(void);
};

#endif