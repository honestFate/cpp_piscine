#ifndef IDENTIFIER_H
#define IDENTIFIER_H

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#define RED "\033[1;91m"
#define GREEN "\033[1;92m"
#define RESET "\033[0m"

void	identify(Base* p);
void	identify(Base& p);

#endif
