#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <memory>

#include "Transaction.h"
#include "FieldsError.h"
#include "Print.h"


void SortTransactions(std::vector<std::deque<std::shared_ptr<Transaction>>>&,
                      std::vector<double>&);

int main(int argc, char *argv[]) {

  const int num_columns = 5;

  std::vector<std::deque<std::shared_ptr<Transaction>>> types(num_columns);

  // Initialize each total to 0
  std::vector<double> totals(num_columns, 0.0);

  // Advance past first line - optimize this? - simply remove the heading from CSV
  std::string header;
  std::getline(std::cin, header);

  try {
    SortTransactions(types, totals);
    Print(types, totals);
  } catch (FieldsError e) {
    e.Message();  
  }

  return 0;
}


/*
 * Sorts transactions into income, expense, etc.
 *
 * types:  a vector of deques of shared pointers to Transactions
 * totals: a vector of doubles representing totals
 *
 */
void SortTransactions(std::vector<std::deque<std::shared_ptr<Transaction>>> &types,
                      std::vector<double> &totals) 
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
      totals[UNDEFINED] += trans->get_amount();
      types[UNDEFINED].push_back(trans);
    } else if (tType == INCOME) {
      totals[INCOME] += trans->get_amount();
      types[INCOME].push_back(trans);
    } else if (tType == EXPENSE) {
      totals[EXPENSE] += trans->get_amount();
      types[EXPENSE].push_back(trans);
    } else if (tType == SAVINGS) {
      totals[SAVINGS] += trans->get_amount(); 
      types[SAVINGS].push_back(trans);
    } else if (tType == OFFSET) {
      totals[OFFSET] += trans->get_amount();
      types[OFFSET].push_back(trans);
    }
  }
}
