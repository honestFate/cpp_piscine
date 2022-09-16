#include "Integer.hpp"
#include "iter.hpp"
#include <cmath>

template<typename T>
void	iter(T * array, size_t arraySize, void (*f)(T &))
{
	std::cout << "Non const iter called" << std::endl;
	for (size_t i = 0; i < arraySize; i++)
	{
		f(array[i]);
	}
}

template<typename T>
void	iter(const T * array, size_t arraySize, void (*f)(const T &))
{
	std::cout << "Const iter called" << std::endl;
	for (size_t i = 0; i < arraySize; i++)
	{
		f(array[i]);
	}
}

template<typename T>
void	ftIsFinite(const T&)
{
	std::cout << "Works only with floating point numbers!" << std::endl;
}

template<>
void	ftIsFinite<float&>(float& flt)
{
	std::cout << flt << " isfinite non const float: " << std::boolalpha << std::isfinite(flt) << std::endl;
}

template<>
void	ftIsFinite<const float&>(const float & flt)
{
	std::cout << flt << " isfinite const float: " << std::boolalpha << std::isfinite(flt) << std::endl;
}

template<>
void	ftIsFinite<double&>(double& dbl)
{
	std::cout << dbl << " isfinite non const double: " << std::boolalpha << std::isfinite(dbl) << std::endl;
}

template<>
void	ftIsFinite<const double&>(const double& dbl)
{
	std::cout << dbl << " isfinite const double: " << std::boolalpha << std::isfinite(dbl) << std::endl;
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
	const int size = 3;
	{
		Integer intArray[size];
		
		for (size_t i = 0; i < size; i++)
		{
			std::cout << "intArray[" << i << "] - " << intArray[i].getX() << std::endl;
		}
		iter<Integer>(intArray, size, &addOne);
		for (size_t i = 0; i < size; i++)
		{
			std::cout << "intArray[" << i << "] - " << intArray[i].getX() << std::endl;
		}
		iter<Integer>(intArray, size, &removeOne);
		iter<Integer>(intArray, size, &removeOne);
		for (size_t i = 0; i < size; i++)
		{
			std::cout << "intArray[" << i << "] - " << intArray[i].getX() << std::endl;
		}
	}
	{
		float *fltArray = new float[size];
		double *dblArray = new double[size];

		for (size_t i = 0; i < size; i++)
		{
			fltArray[i] = 2.1f;
		}
		for (size_t i = 0; i < size; i++)
		{
			dblArray[i] = 4.2f;
		}

		iter<float>(static_cast<const float *>(fltArray), size, &ftIsFinite<const float&>);
		iter<float>(fltArray, size, &ftIsFinite<float&>);
		iter<double>(static_cast<const double *>(dblArray), size, &ftIsFinite<const double&>);
		iter<double>(static_cast<double *>(dblArray), size, &ftIsFinite<double&>);

		delete[] dblArray;
		delete[] fltArray;
	}

	return 0;
}
