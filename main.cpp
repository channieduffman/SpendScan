#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <memory>

#include "Transaction.h"
#include "FieldsError.h"
#include "Print.h"


void SortTransactions(std::deque<std::shared_ptr<Transaction>>&, 
                      std::deque<std::shared_ptr<Transaction>>&,
                      std::deque<std::shared_ptr<Transaction>>&,
                      std::deque<std::shared_ptr<Transaction>>&,
                      std::vector<float>&);

int main(int argc, char *argv[]) {

  // Initialize empty vectors of Transaction pointers
  std::deque<std::shared_ptr<Transaction>> undefined;
  std::deque<std::shared_ptr<Transaction>> income;
  std::deque<std::shared_ptr<Transaction>> expense;
  std::deque<std::shared_ptr<Transaction>> savings;

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

  Print(undefined, income, expense, savings, totals);

  return 0;
}


/*
 * Parses CSV file of transactions and sorts them into correct vectors
 *
 * u: deque of undefined transactions
 * i: deque of income transactions
 * e: deque of expense transactions
 * s: deque of savings transactions
 * t: vector of total values
 *
 */
void SortTransactions(std::deque<std::shared_ptr<Transaction>> &u, 
                      std::deque<std::shared_ptr<Transaction>> &i,
                      std::deque<std::shared_ptr<Transaction>> &e,
                      std::deque<std::shared_ptr<Transaction>> &s,
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

    std::shared_ptr<Transaction> trans = std::make_shared<Transaction>(fields[0], 
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
