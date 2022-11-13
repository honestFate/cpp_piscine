#pragma once
#ifndef EASYFIND_H
#define EASYFIND_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <ctime>
#include <cstdlib>
#include <sstream>

template<typename T>
typename T::iterator	easyfind(T& haystack, int needle);

#endif
