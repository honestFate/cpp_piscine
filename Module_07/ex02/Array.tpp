#include "Array.hpp"

template<typename T>
Array<T>::Array() : _array(new T[0]()), _size(0)
{
	std::cout << "Array<T> object created by default constructor" << std::endl;
}

template<typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n)
{
	std::cout << "Array<T> size of " << n << " created" << std::endl;
}

template<typename T>
Array<T>::~Array()
{
	delete[] _array;
	std::cout << "Array<T> object deleted" << std::endl;
}

template<typename T>
Array<T>::Array(const Array<T>& src) : _size(0)
{
	std::cout << "Array<T> copy constructor" << std::endl;
	*this = src;
}

template<typename T>
const Array<T>& Array<T>::operator=(const Array<T>& src)
{
	if (this != &src)
	{
		if (this->_size != 0)
		{
			delete[] this->_array;
		}
		this->_array = new int[src.size()];
		for (size_t i = 0; i < src.size(); i++)
		{
			this->_array[i] = src._array[i];
		}
	}
	return *this;
}

template<typename T>
T&	Array<T>::operator[](int index)
{
	if (static_cast<size_t>(index) >= _size || index < 0)
	{
		throw std::exception();
	}
	return _array[index];
}

template<typename T>
size_t	Array<T>::size() const
{
	return this->_size;
}
