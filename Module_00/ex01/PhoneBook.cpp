#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void ) : _contactIndex(0), _contactCount(0) {
	this->_set[FIRST_NAME] = &Contact::setFirstName;
	this->_set[LAST_NAME] = &Contact::setLastName;
	this->_set[NICKNAME] = &Contact::setNickname;
	this->_set[PHONE] = &Contact::setPhoneNumber;
	this->_set[SECRET] = &Contact::setDarkestSecret;
	this->_get[FIRST_NAME] = &Contact::getFirstName;
	this->_get[LAST_NAME] = &Contact::getLastName;
	this->_get[NICKNAME] = &Contact::getNickname;
	this->_get[PHONE] = &Contact::getPhoneNumber;
	this->_get[SECRET] = &Contact::getDarkestSecret;
	return;
}

PhoneBook::~PhoneBook( void ) {
	return;
}

void	PhoneBook::commandLoop( void ) {
	std::string line;

	std::cout << "Enter command: ";
	while (std::getline(std::cin, line)) {
		if (line == ADD) {
			this->_addContact();	
		}
		else if (line == SEARCH) {
			this->_searchContact();
		}
		else if (line == EXIT) {
			break;
		}
		else {
			std::cout << "Command " << line << " not found" << std::endl;
			std::cout << "Only ADD, SEARCH and EXIT commands allowed" << std::endl;
		}
		if (std::cin)
			std::cout << "Enter command: ";
	}
	if (!std::cin)
		std::cout << std::endl;
}

void	PhoneBook::_showPromt( int index ) const {
	if (index == FIRST_NAME)
		std::cout << "first name: ";
	else if (index == LAST_NAME)
		std::cout << "last name: ";
	else if (index == NICKNAME)
		std::cout << "nickname: ";
	else if (index == PHONE)
		std::cout << "phone number: ";
	else if (index == SECRET)
		std::cout << "darkest secret: ";
}

void	PhoneBook::_addContact( void ) {
	std::string	data;
	int			index = 0;

	while (index < 5)
	{
		std::cout << "Enter ";
		this->_showPromt(index);
		if (!std::getline(std::cin, data))
			return;
		if (!(this->_contacts[this->_contactIndex].*this->_set[index])(data)) {
			++index;
		}
		else
			std::cout << "Invalid value" << std::endl;
	}
	if (this->_contactIndex == PB_CAPACITY - 1)
		this->_contactIndex = 0;
	else
		this->_contactIndex++;
	if (this->_contactCount < PB_CAPACITY)
		this->_contactCount++;
}

void	PhoneBook::_searchContact( void ) const {
	int	index;

	this->_showContactList();
	if (!this->_contactCount)
		return;
	index = this->_get_index();
	if (index < 0)
		return;	
	for (int i = 0; i < 5; i++)
	{
		this->_showPromt(i);
		std::cout << (this->_contacts[index - 1].*this->_get[i])() << std::endl;
	}
}

std::string PhoneBook::_truncate( std::string line ) const {
	if (line.length() <= 10)
		return (line);
	return line.substr(0, 9) + ".";
}

void	PhoneBook::_showContactList( void ) const {
	std::cout << std::setw(11) << std::right << "index|";
	std::cout << std::setw(11) << std::right << "first name|";
	std::cout << std::setw(11) << std::right << "last name|";
	std::cout << std::setw(10) << std::right << "nickname" << std::endl;
	for (int i = 0; i < this->_contactCount; i++)
	{
		std::cout << std::setw(10) << std::right << i + 1 << "|";
		for (int j = 0; j < 3; j++)
		{
			std::cout << std::setw(10) << std::right
			<< this->_truncate((this->_contacts[i].*this->_get[j])());
			if (j < 2)
				std::cout << "|";
		}
		std::cout << std::endl;
	}
}

int	PhoneBook::_get_index( void ) const {
	bool		digit;
	std::string	line;
	int			index;

	while (1)
	{
		std::cout << "Enter index ";
		if (!std::getline(std::cin, line))
			return (-1);
		digit = true;
		for (size_t i = 0; i < line.length(); i++)
		{
			if (!isdigit(line[i]))
			{
				digit = false;
				break;
			}
		}
		if (digit && line.length() == 1)
		{
			index = line[0] - '0';
			if (1 <= index && index <= this->_contactCount)
				break;
		}
		std::cout << "No contact with this index" << std::endl;
	}
	return (index);
}
