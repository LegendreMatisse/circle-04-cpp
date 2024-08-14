/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:51:28 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/14 16:51:28 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	private:
		std::string	_ideas[100];

	public:
		//constructor
		Brain(void);

		//copy constructor
		Brain(const Brain &copyCo)

		//assignment operator overload
		Brain &operator=(const Dog &copyOp)

		//destructor
		~Brain();

		//getter
		std::string	&getIdea(const int i) const;

		//setter
		void				setIdea(const std::string &idea, int i);
};

#endif