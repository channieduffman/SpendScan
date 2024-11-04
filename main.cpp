#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>

#include "Transaction.h"
#include "FieldsError.h"
#include "Print.h"


void SortTransactions(std::deque<Transaction*>&, 
                      std::deque<Transaction*>&,
                      std::deque<Transaction*>&,
                      std::deque<Transaction*>&,
                      std::vector<float>&);

int main(int argc, char *argv[]) {

  // Initialize empty vectors of Transaction pointers
  std::deque<Transaction*> undefined;
  std::deque<Transaction*> income;
  std::deque<Transaction*> expense;
  std::deque<Transaction*> savings;

  // Initialize each total to 0
  std::vector<float> totals(4, 0);

  // Advance past first line - optimize this? - simply remove the heading from CSV
  std::string header;
  std::getline(std::cin, header);

  try {
    SortTransactions(undefined, income, expense, savings, totals);
  } catch (FieldsError e) {
    e.Message();  
  }

  Print(undefined, income, expense, savings);

  return 0;
}


/*
 * Parses CSV file of transactions and sorts them into correct vectors
 *
 * u: vector of undefined transactions
 * i: vector of income transactions
 * e: vector of expense transactions
 * s: vector of savings transactions
 * t: vector of total values
 *
 */
void SortTransactions(std::deque<Transaction*> &u, 
                      std::deque<Transaction*> &i,
                      std::deque<Transaction*> &e,
                      std::deque<Transaction*> &s,
                      std::vector<float> &t) 
{
  const int expected_fields = 4;

  std::string line;
  while (std::getline(std::cin, line)) {
    std::istringstream ln{line};

    std::string field;
    std::vector<std::string> fields;

    // Push each comma-separated field to a vector
    while (std::getline(ln, field, ',')) {
      fields.push_back(field);
    }

    // Expected fields: description, date, amount, end_balance
    if (fields.size() != expected_fields) { throw FieldsError(expected_fields, fields.size()); }

    Transaction *trans = new Transaction(fields[0], 
                                         fields[1], 
                                         std::stof(fields[2]), 
                                         std::stof(fields[3]));    

    trans->Categorize();

    TransType tType = trans->get_type();
    
    // Accumulate totals
    if (tType == UNDEFINED) {
      t[UNDEFINED] += trans->get_amount();
      u.push_back(trans);
    } else if (tType == INCOME) {
      t[INCOME] += trans->get_amount();
      i.push_back(trans);
    } else if (tType == EXPENSE) {
      t[EXPENSE] += trans->get_amount();
      e.push_back(trans);
    } else if (tType == SAVINGS) {
      t[SAVINGS] += trans->get_amount(); 
      s.push_back(trans);
    }
  }
}
