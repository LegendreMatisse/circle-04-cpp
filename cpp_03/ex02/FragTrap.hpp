/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 22:30:47 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/11 22:30:47 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		//constructor
		FragTrap(void);

		//parameterized constructor
		FragTrap(std::string const &name);

		//copy constructor
		FragTrap(const FragTrap &copyCo);

		//assignment operator overload
		FragTrap &operator=(const FragTrap &copyOp);

		//destructor
		~FragTrap();

		//functions
		void	highFivesGuys(void);
};