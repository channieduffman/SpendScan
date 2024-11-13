#ifndef PRINT_H
#define PRINT_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <memory>

#include "Transaction.h"


const char SIDE_BORDER = '|';
const char TOP_BOT_BORDER = '-';

void Print(std::vector<std::deque<std::shared_ptr<Transaction>>>&, std::vector<double>&);

void SetValues(std::deque<std::shared_ptr<Transaction>>&, std::string&);

void Line(int, char);

template <typename T>
void PrintRow(std::vector<T> &values, int col_width) {
  for (auto value : values) {
    std::cout << SIDE_BORDER << " " << std::setw(col_width) << std::left << value;
  }
  std::cout << SIDE_BORDER << std::endl;
}

#endif
