/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:20:22 by mlegendr          #+#    #+#             */
/*   Updated: 2024/09/01 19:20:22 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include "AForm.hpp"

class RobotomyRequestForm
{
	private:
		std::string _target;
		
	public:
		//constructor
		RobotomyRequestForm(void);

		//parameterised constructor
		RobotomyRequestForm(std::string target);

		//copy constructor
		RobotomyRequestForm(const RobotomyRequestForm &copyCo);

		//Assignment operator overload
		RobotomyRequestForm &operator=(const RobotomyRequestForm &copyOp);

		//destructor
		virtual ~RobotomyRequestForm();

		//functions
		virtual void	specialFeature(void) const;
};

#endif
