/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:18:58 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/19 19:43:33 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Form
{
	private:
		bool				_signed;
		const std::string	_name;
		const unsigned int	_signGrade;
		const unsigned int	_execGrade;

	public:
		//constructor
		Form(void);

		//parameterised constructor
		Form(const std::string &name, int &signGrade, int &execGrade);

		//copy constructor
		Form(const Form &copyCo);

		//assignement operator overload
		Form &operator=(const Form &copyOp);

		//destructor
		~Form();

		//getters
		bool			getSigned(void);
		std::string		getName(void);
		unsigned int	getSignGrade(void);
		unsigned int	getExecGrade(void);

		//functions
		void			beSigned(const Bureaucrat &bureaucrat);

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
};

std::ostream &operator<<(std::ostream &out, Form const &value);

#endif