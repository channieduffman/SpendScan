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

void Print(std::deque<std::shared_ptr<Transaction>>&,
           std::deque<std::shared_ptr<Transaction>>&,
           std::deque<std::shared_ptr<Transaction>>&,
           std::deque<std::shared_ptr<Transaction>>&,
           std::vector<float>&);

void SetValues(std::deque<std::shared_ptr<Transaction>>&, std::string&);

#endif
