#include "Sed.hpp"

void	test(std::string const & file, std::string const & s1, std::string const & s2, std::string const res[], int res_size) {
	Sed*	seder;

	seder = Sed::init(file);
	if (!seder)
	{
		std::cout << "File error " << file << std::endl;
		return;
	}
	seder->sed(s1, s2);
	delete seder;

	std::ifstream infile(file + ".replace");
	if (!infile.is_open())
	{
		std::cout << "File error " << file + ".replace" << std::endl;
		return;
	}
	int	i = 0;
	std::string	s;
	while (std::getline(infile, s))
	{
		if (i > res_size || res[i] != s)
		{
			std::cout << file << " ERROR" << std::endl;
			std::cout << "EXPECTED: " << res[i] << std::endl;
			std::cout << "GOT: " << s << std::endl;
			break;
		}
		++i;
	}
	if (i == 0 && s.empty() && res_size == 1 && res[0].empty())
		return;
	if (i != res_size)
		std::cout << file << " ERROR" << std::endl;
}

int	main() {
	std::string	res0[3] = {"my test here", "my test here", "my test here"};
	std::string	res1[5] = {"replase replase", "", " ", "", "Replace"};
	std::string	res2[1] = {""};
	std::ofstream outfile("test0");

	outfile << "my text here" << std::endl
			<< "my text here" << std::endl
			<< "my text here" << std::endl;
	outfile.close();

	std::ofstream outfile1("test1");
	outfile1 << "replase replase" << std::endl
			<< "replace" << std::endl
			<< "replace replace" << std::endl
			<< "replacereplacereplace" << std::endl
			<< "Replace" << std::endl;
	outfile1.close();

	std::ofstream outfile2("test2");
	outfile2 << std::endl;
	outfile2.close();

	test("test0", "ex", "es", res0, sizeof(res0)/sizeof(res0[0]));
	test("test1", "replace", "", res1, sizeof(res1)/sizeof(res1[0]));
	test("test2", "", "", res2, sizeof(res2)/sizeof(res2[0]));
	std::cout << "TEST END"<< std::endl;
}
