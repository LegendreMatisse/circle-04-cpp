/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:33:03 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/21 13:18:40 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	protected:
		std::string _type;

	public:
		//constructor
		Animal(void);

		//copy constructor
		Animal(const Animal &copyCo);

		//assignment operator overload
		Animal &operator=(const Animal &copyOp);

		//destructor
		virtual ~Animal();

		//getter
		std::string		getType(void) const;

		//setter
		void			setType(std::string const &type);

		//functions
		virtual void	makeSound(void) const;
};

#endif