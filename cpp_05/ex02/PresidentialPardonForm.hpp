/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:20:18 by mlegendr          #+#    #+#             */
/*   Updated: 2024/09/01 19:20:18 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string		_target;

	public:
		//constructor
		PresidentialPardonForm(void);

		//parameterised constructor
		PresidentialPardonForm(std::string target);

		//copy constructor
		PresidentialPardonForm(const PresidentialPardonForm &copyCo);

		//Assignment operator overload
		PresidentialPardonForm &operator=(const PresidentialPardonForm &copyOp);

		//destructor		
		virtual ~PresidentialPardonForm();

		//functions
		virtual void	specialFeature(void) const;
};

#endif