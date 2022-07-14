#include "Contact.hpp"


Contact::Contact( void ) {
	return;
}

Contact::~Contact( void ) {
	return;
}

std::string Contact::getFirstName( void ) const {
	return this->_firstName;
}

std::string Contact::getLastName( void ) const {
	return this->_lastName;
}

std::string Contact::getNickname( void ) const {
	return this->_nickname;
}

std::string	Contact::getPhoneNumber( void ) const {
	return this->_phoneNumber;
}

std::string	Contact::getDarkestSecret( void ) const {
	return this->_darkestSecret;
}

int	Contact::setFirstName( std::string data ) {
	if (data.length() == 0)
		return (1);
	this->_firstName = data;
	return (0);
}

int	Contact::setLastName( std::string data ) {
	if (data.length() == 0)
		return (1);
	this->_lastName = data;
	return (0);
}

int	Contact::setNickname( std::string data ) {
	if (data.length() == 0)
		return (1);
	this->_nickname = data;
	return (0);
}

int	Contact::setPhoneNumber( std::string data ) {
	if (data.length() == 0)
		return (1);
	for (size_t i = 0; i < data.length(); i++)
	{
		if (!isdigit(data[i]))
			return (1);
	}
	this->_phoneNumber = data;
	return (0);
}

int	Contact::setDarkestSecret( std::string data ) {
	if (data.length() == 0)
		return (1);
	this->_darkestSecret = data;
	return (0);
}