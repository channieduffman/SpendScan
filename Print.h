#ifndef PRINT_H
#define PRINT_H

#include <vector>
#include <deque>
#include "Transaction.h"


void Line(int, char);

void PrintRow(const std::string&, 
              const std::string&, 
              const std::string&, 
              const std::string&,
              int);

void Print(std::deque<Transaction*> &u,
           std::deque<Transaction*> &i,
           std::deque<Transaction*> &e,
           std::deque<Transaction*> &s);

#endif
