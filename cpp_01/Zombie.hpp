/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:13:19 by mlegendr          #+#    #+#             */
/*   Updated: 2024/07/31 20:25:58 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	private:
		std::string	_name;
	public:
		Zombie(void);	//constructor
		~Zombie();		//destructor

		//getters
		std::string	getName(void) const;
		
		//setters
		void		setName(std::string &name);

		//functions
		void		announce(void);
};

#endif