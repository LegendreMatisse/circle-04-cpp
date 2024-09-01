/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:20:12 by mlegendr          #+#    #+#             */
/*   Updated: 2024/09/01 19:20:12 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		bool				_signed;
		const std::string	_name;
		const unsigned int	_signGrade;
		const unsigned int	_execGrade;

	public:
		//constructor
		AForm(void);

		//parameterised constructor
		AForm(const std::string &name, const unsigned int &signGrade, const unsigned int &execGrade);

		//copy constructor
		AForm(const AForm &copyCo);

		//assignement operator overload
		AForm &operator=(const AForm &copyOp);

		//destructor
		~AForm();

		//getters
		bool			getSigned(void) const;
		std::string		getName(void) const;
		unsigned int	getSignGrade(void) const;
		unsigned int	getExecGrade(void) const;

		//functions
		void			beSigned(const Bureaucrat &bureaucrat);
		void			execute(const Bureaucrat &executor) const;
		virtual void	specialFeature(void) const = 0;

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class FormSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, AForm const &value);

#endif