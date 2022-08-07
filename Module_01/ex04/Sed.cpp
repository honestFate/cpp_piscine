#include "Sed.hpp"

Sed::Sed( void ) {
	return;
}

Sed::~Sed() {
	return;
}

bool	Sed::init_stream( std::string const & filename ) {
	this->_ifs.open( filename.c_str() );
	return (this->_ifs.is_open());
}

bool	Sed::open_output_file( std::string const & filename ) {
	this->_ofs.open((filename + ".replace").c_str());
	return (this->_ofs.is_open());
}

Sed* Sed::init( std::string const & filename ) {
	Sed*			seder;
	std::ifstream	ifs;

	seder = new Sed();
	if (seder->init_stream(filename)) {
		if (seder->open_output_file(filename))
			return (seder);
	}
	delete seder;
	return (NULL);
}

void	Sed::sed( std::string const & s1, std::string const & s2 ) {
	std::string	buf;
	size_t		pos;

	if (s1.empty())
		return;
	while (std::getline(this->_ifs, buf))
	{
		while ((pos = buf.find(s1)) != std::string::npos)
		{
			buf.erase(pos, s1.length());
			buf.insert(pos, s2);
		}
		this->_ofs << buf;
		if (!this->_ifs.eof())
			this->_ofs << std::endl;
	}
}
