#include "Converter.hpp"

int main(int argc, char * argv[])
{
	if (argc != 2)
	{
		std::cout << "Must be one and only one argument!" << std::endl;
		return 1;
	}

	Converter conv(argv[1]);
	conv.convert();

	return 0;
}
