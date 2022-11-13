#include "easyfind.hpp"
#include <cmath>

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

template<typename T>
void	printVec(const std::vector<T> & vec)
{
	std::cout << "The numbers in vector with size " << vec.size() << std::endl;
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}

template<typename T>
void	fillVec(std::vector<T> & vec)
{
	std::istream_iterator<int> begin(std::cin), end;
	std::copy(begin, end, std::back_inserter(vec));
}

int main()
{
	int					num_to_search;
	std::vector<int>	vec;
	
	fillVec(vec);
	printVec(vec);
	if (std::cin.eof())
		return 1;

	std::cout << "Search..." << std::endl;
	std::cin.clear();
	std::cin.ignore(1);
	std::cin >> num_to_search;
	std::vector<int>::iterator it = easyfind(vec, num_to_search);
	std::cout << "Result - " << *it << std::endl;
	return 0;
}
