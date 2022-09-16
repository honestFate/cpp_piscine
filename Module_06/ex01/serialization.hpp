#pragma once
#ifndef SERIALIZATION_H
#define SERIALIZATION_H

#include <cstdint>
#include "Data.hpp"

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif
