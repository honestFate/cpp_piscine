#pragma once
#ifndef CONTACT_H
# define CONTACT_H

# include <string>

class Contact
{


public:

	Contact( void );
	~Contact();

	std::string	getFirstName( void ) const;
	std::string	getLastName( void ) const;
	std::string	getNickname( void ) const;
	std::string	getPhoneNumber( void ) const;
	std::string	getDarkestSecret( void ) const;
	int			setFirstName( std::string data );
	int			setLastName( std::string data );
	int			setNickname( std::string data );
	int			setPhoneNumber( std::string data );
	int			setDarkestSecret( std::string data );

private:

	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;


};


#endif