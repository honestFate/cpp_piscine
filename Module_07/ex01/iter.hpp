#pragma once
#ifndef ITER_H
#define ITER_H

#include <iostream>

template<typename T>
void	iter(T * array, size_t arraySize, void (*f)(T &));

template<typename T>
void	iter(T const * array, size_t arraySize, void (*f)(const T &));

template<typename T>
void	ftIsFinite(T&);

template<>
void	ftIsFinite<float>(float &);

template<>
void	ftIsFinite<const float>(const float &);

template<typename T>
void	addOne(T &);

template<typename T>
void	removeOne(T &);

#endif
