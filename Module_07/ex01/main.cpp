#include "iter.hpp"
#include "Integer.hpp"

template<typename T>
void	iter(T * array, size_t arraySize, void (*f)(T &))
{
	for (size_t i = 0; i < arraySize; i++)
	{
		f(array[i]);
	}
}

template<typename T>
void	iter(T const * array, size_t arraySize, void (*f)(const T &))
{
	for (size_t i = 0; i < arraySize; i++)
	{
		f(array[i]);
	}
}

template<typename T>
void	ftIsFinite(const T &)
{
	std::cout << "Works only with floating point numbers!" << std::endl;
}

template<typename T>
void	ftIsFinite<float>(const float & flt)
{
	std::cout << flt << " isfinite float: " << std::boolalpha << isfinite(flt) << std::endl;
}

template<typename T>
void	ftIsFinite<double>(const double & dbl)
{
	std::cout << dbl << " isfinite double: " << std::boolalpha << isfinite(dbl) << std::endl;
}

template<typename T>
void	addOne(T & i)
{
	++i;
}

template<typename T>
void	removeOne(T &i)
{
	--i;
}

int main()
{
	Integer intArray[3];
	
	for (size_t i = 0; i < 3; i++)
	{
		std::cout << "intArray[" << i << "] - " << intArray[i].getX() << std::endl;
	}
	iter<Integer>(intArray, 3, &addOne);
	for (size_t i = 0; i < 3; i++)
	{
		std::cout << "intArray[" << i << "] - " << intArray[i].getX() << std::endl;
	}
	return 0;
}

