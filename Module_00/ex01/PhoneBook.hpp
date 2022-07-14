#pragma once
#ifndef PHONEBOOK_H
# define PHONEBOOK_H


# include <iostream>
# include <iomanip>
# include <string>
# include "Contact.hpp"

# define ADD "ADD"
# define SEARCH "SEARCH"
# define EXIT "EXIT"
# define PB_CAPACITY 8
# define FIRST_NAME 0
# define LAST_NAME 1
# define NICKNAME 2
# define PHONE 3
# define SECRET 4


class PhoneBook
{


public:

	PhoneBook( void );
	~PhoneBook( void );

	void		commandLoop( void );

private:

	Contact		_contacts[PB_CAPACITY];
	int			(Contact::*_set[5])( std::string );
	std::string	(Contact::*_get[5])( void ) const;
	int			_contactIndex;
	int			_contactCount;

	void		_addContact( void );
	void 		_searchContact( void ) const;
	void		_showPromt( int index ) const;
	void		_showContactList( void ) const;
	int			_get_index( void ) const;
	std::string	_truncate( std::string line ) const;


};


#endif
