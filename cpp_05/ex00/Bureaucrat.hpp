/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 21:56:35 by mlegendr          #+#    #+#             */
/*   Updated: 2024/09/19 15:18:52 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat
{
	private:
		const std::string	_name;
		unsigned int		_grade;

	public:
		//constructor
		Bureaucrat(void);

		//parameterised constructor
		Bureaucrat(const std::string &name, unsigned int &grade);

		//copy constructor
		Bureaucrat(const Bureaucrat &copyCo);

		//assignment operator overload
		Bureaucrat &operator=(const Bureaucrat &copyOp);
		
		//destructor
		~Bureaucrat();

		//getters
		std::string			getName(void) const;
		unsigned int		getGrade(void) const;

		//functions
		void				incrementGrade(void);
		void				decrementGrade(void);

		//exception classes
		/*
			Brief explanation:
			¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
			Firstly, we declare a new class that inherits from the exception class.
			This way this class becomes a custom exception type, it can now be used
			in a try-catch block like any other exception.

			virtual const char *what() const throw();
			¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
			By using virtual we show that we are overwriting the orignal <what> function.
			We are returning a constant char* containing a message that describes the exception.
			The <const> keyword "promises" that we will not modify the member variables of the class.
			The <throw> keyword specifies that this function will not throw any exceptions.
		*/
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

std::ostream &operator<<(std::ostream &out, Bureaucrat const &value);

#endif
