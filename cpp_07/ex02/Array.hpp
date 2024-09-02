/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:26:44 by mlegendr          #+#    #+#             */
/*   Updated: 2024/09/02 17:26:44 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array
{
	private:
		T				*_arr;
		unsigned int	_size;
	public:
		//constructor
		Array(void);

		//parameterized constructor
		Array(unsigned int n);

		//copy constructor
		Array(const Array &copyCo);

		//copy assignment operator
		Array &operator=(const Array &copyOp);

		//destructor
		~Array();

		//operator overload
		T &operator[](unsigned int index);
};

template <typename T>
Array<T>::Array(void) : _arr(NULL), _size(0)
{
	std::cout << "An instance of Array was created." << std::endl;
}
Array<T>::Array(unsigned int n) : _arr(new T[n]), _size(n)
{
	std::cout << "An instance of Array was created with parameters." << std::endl;
}

Array<T>::Array(const Array &copyCo)
{
	*this = copyCo;
	std::cout << "An instance of Array was created by copy." << std::endl;
}

Array<T> &Array<T>::operator=(const Array &copyOp)
{
	if (this == &copyOp)
		return *this;
	if (_arr)
		delete[] _arr;
	this->_size = copyOp._size;
	this->_array = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
	{
		this->_arr[i] = copyOp._arr[i];
	}
	std::cout << "An instance of Array has been assigned." << std::endl;
	return *this;
}

Array<T>::~Array()
{
	if (this->_arr)
		delete[] _arr;
	std::cout << "An instance of Array was destroyed." << std::endl;
}

Array<T> &Array<T>::operator[](unsigned int index)
{
	if (index >= this->_size)
		throw std::out_of_range("The index has gone out of bounds.");
	return this->_arr[index];
}
#endif