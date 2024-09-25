/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:25:46 by mlegendr          #+#    #+#             */
/*   Updated: 2024/09/24 18:26:05 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_TPP

# include <stack>
# include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
	private:

	public:
		//iterators
		typedef typename std::stack<T>::container_type::iterator it;
		typedef typename std::stack<T>::container_type::reverse_iterator revIt;

		//constructor
		MutantStack();

		//copy constructor
		MutantStack(const MutantStack &copyCo);

		//assignment operator overload
		MutantStack &operator=(const MutantStack &copyOp);

		//destructor
		virtual ~MutantStack();

		//funtions
		iterator			begin();
		iterator			end();
		reverse_iterator	rbegin();
		reverse_iterator	rend();
};

# include "MutantStack.tpp"

#endif