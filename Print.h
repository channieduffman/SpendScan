#ifndef PRINT_H
#define PRINT_H

#include <vector>
#include <deque>
#include <memory>
#include "Transaction.h"


void Line(int, char);

void PrintRow(const std::string&, 
              const std::string&, 
              const std::string&, 
              const std::string&,
              int);

void Print(std::deque<std::shared_ptr<Transaction>> &u,
           std::deque<std::shared_ptr<Transaction>> &i,
           std::deque<std::shared_ptr<Transaction>> &e,
           std::deque<std::shared_ptr<Transaction>> &s,
           std::vector<float> &t);

#endif
