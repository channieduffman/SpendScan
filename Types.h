#ifndef TYPES_H
#define TYPES_H

#include <string>

enum TransType { 
  UNDEFINED = 0, INCOME, EXPENSE, SAVINGS, OFFSET
};

std::string ExtractTypeString(int);

#endif
