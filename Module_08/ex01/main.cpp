#include "Span.hpp"

int main()
{
	Span a(5);
	Span b(10);
	a.fillRandom();
	b = a;
	a.printVec();
	b.printVec();
	{
		Span test(5);
		std::istream_iterator<int> begin(std::cin), end;
		try
		{
			std::for_each(begin, end, std::bind1st(std::mem_fun(&Span::addNumber), &test));
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			return 1;
		}
		test.printVec();
		try
		{
			std::cout << "shortest " << test.shortestSpan() << std::endl;
			std::cout << "longest " << test.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		Span sp = Span(100);
		sp.fillRandom();
		std::cout << "shortest span - " << sp.shortestSpan() << std::endl;
		std::cout << "longest span - " << sp.longestSpan() << std::endl;
		sp.printVec();
	}
	return 0;
}
