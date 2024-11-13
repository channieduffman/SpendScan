#ifndef TYPES_H
#define TYPES_H

#include <string>
#include <unordered_map>

// Add new types here and to the map in Types.cpp
enum TransType { 
  UNDEFINED = 0, INCOME, EXPENSE, SAVINGS, OFFSET
};

std::unordered_map<int, std::string> MapTypes();
std::string ExtractTypeString(int);
int NumTypes();

#endif
