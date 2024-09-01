/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:20:27 by mlegendr          #+#    #+#             */
/*   Updated: 2024/09/01 19:20:27 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string		_target;

	public:
		//constructor
		ShrubberyCreationForm(void);

		//parameterised constructor
		ShrubberyCreationForm(std::string target);

		//copy constructor
		ShrubberyCreationForm(const ShrubberyCreationForm &copyCo);

		//Assignment operator overload
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copyOp);

		//destructor		
		~ShrubberyCreationForm();

		//functions
		virtual void	specialFeature(void) const;
};

#endif
