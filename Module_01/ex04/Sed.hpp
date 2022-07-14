#pragma once
#ifndef SED_H
# define SED_H

# include <iostream>
# include <fstream>
# include <string>

class Sed
{


private:

	std::ifstream	_ifs;
	std::ofstream	_ofs;

	Sed( void );

	bool		init_stream( std::string const & filename );
	bool		open_output_file( std::string const & filename );


public:

	~Sed();

	static Sed*	init( std::string const & filename );

	void		sed( std::string const & s1, std::string const & s2 );

};


#endif