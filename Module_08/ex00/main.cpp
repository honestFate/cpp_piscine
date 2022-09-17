#include <algorithm>
#include <vector>
#include <iostream>

template<typename T>
typename T::iterator	easyfind(T& haystack, int needle)
{
	typename T::iterator res = std::find(haystack.begin(), haystack.end(), needle);
	if (res == haystack.end())
	{
		throw std::exception();
	}
	return res;
}

int main()
{
	std::vector<int> vec(2, 100);
	vec.push_back(2);
	// if ( std::find(vec.begin(), vec.end(), 1) != vec.end() )
	// 	std::cout << "true" << std::endl;
	// else
	// 	std::cout << "false" << std::endl;
	// std::for_each(vec.begin(), vec.end(), &printInt);
	try
	{
		std::vector<int>::iterator it = easyfind(vec, 1);
		std::cout << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}

