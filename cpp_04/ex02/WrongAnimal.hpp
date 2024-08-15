/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 00:42:58 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/13 00:42:58 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
	protected:
		std::string _type;

	public:
		//constructor
		WrongAnimal(void);

		//copy constructor
		WrongAnimal(const WrongAnimal &copyCo);

		//assignment operator overload
		WrongAnimal &operator=(const WrongAnimal &copyOp);

		//destructor
		virtual ~WrongAnimal();

		//getter
		std::string		getType(void) const;

		//setter
		void			setType(std::string const &type);

		//functions
		virtual void	makeSound(void) const;
};

#endif