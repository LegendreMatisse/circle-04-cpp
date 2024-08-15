/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 22:49:43 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/12 22:49:43 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *_brain;

	public:
		//constructor
		Cat(void);

		//copy constructor
		Cat(const Cat &copyCo);

		//assignment operator overload
		Cat &operator=(const Cat &copyOp);

		//destructor
		virtual ~Cat();

		//functions
		virtual void	makeSound(void) const;
		const Brain		*getBrainAddress(void) const;
};

#endif