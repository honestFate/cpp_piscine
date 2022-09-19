#include "Span.hpp"

int main()
{
	{
		Span test;
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
		std::cout << "shortest " << test.shortestSpan() << std::endl;
		std::cout << "longest " << test.longestSpan() << std::endl;
	}
	{
		Span sp = Span(5);
		sp.fillRandom();
		sp.printVec();
		Span a = sp;
		a.printVec();
		Span b;
		b = a;
		b.printVec();
		b.fillRandom();
		b.printVec();
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	return 0;
}
