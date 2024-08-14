/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:16:31 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/12 18:16:31 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *_brain;

	public:
		//constructor
		Dog(void);

		//copy constructor
		Dog(const Dog &copyCo);

		//assignment operator overload
		Dog &operator=(const Dog &copyOp);

		//destructor
		virtual ~Dog();

		//functions
		virtual void	makeSound(void) const;
};

#endif